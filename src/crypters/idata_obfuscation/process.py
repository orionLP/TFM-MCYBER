import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.obfuscation.utils.scope as scope
import src.lib.obfuscation.control.opaqueif as opaqueif
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.control.opaquevariable as opaquevariable
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.visitors.opaqueifvisitor as opaqueifvisitor
import src.lib.obfuscation.visitors.opaquevariablevisitor as opaquevariablevisitor

from src.lib.crypto.rng import prng
from pycparser import c_generator

import pycparser
import secrets
import sys

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input.c> <output.c> [seed]")
        sys.exit(1)

    input_file  = sys.argv[1]
    output_file = sys.argv[2]
    seed = None
    if len(sys.argv) == 4:
        print('Using selected seed...')
        seed = sys.argv[3]
        key = seed[:prng.key_length * 2]
        nonce = seed[prng.key_length * 2: (prng.key_length + prng.nonce_length) * 2]
        prng.key = bytes.fromhex(key)
        prng.nonce = bytes.fromhex(nonce)
        prng.commit_changes()
    else:
        print("No seed was given, using a random seed...")

    ast = pycparser.parse_file(
        input_file,
        use_cpp=True,
        cpp_path='cpp',
        cpp_args=['-I./src/fake_imports']
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

    print('Creating opaque if objects...')

    junk_if = opaqueif.JunkOpaqueIf(builder)
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

    print('Creating visitors to inject opaque true ifs...')
    if_injection_visitors = []
    for opaque_predicate in [is_odd_or_two_predicate, pythagorean_triple_predicate, dummy_predicate]:
        for opaque_if in [junk_if, bogus_flow_if]:
            if_injection_visitors.append(opaqueifvisitor.TrueOpaqueIfVisitor(opaque_predicate, opaque_if, variable_type, scope_handler, 16, 0.3))

    for iiv in if_injection_visitors:
        iiv.visit(ast)


    gen = pycparser.c_generator.CGenerator()
    result = gen.visit(ast)

    with open(output_file, 'w') as f:
        f.write(result)
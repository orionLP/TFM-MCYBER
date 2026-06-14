#!/bin/bash

source_directory="./data/raw/exe/x86/"
 
destination_directory="./data/crypters/exe/x86/code_obfuscation/opaque_ifs/"

mkdir -p "./src/crypters/code_obfuscation/temporary_codes/"
mkdir -p "${destination_directory}"

for file in $(ls ${source_directory}); do
    echo "Processing file ${file}"
    cp "./src/crypters/code_obfuscation/merged.c" "./src/crypters/code_obfuscation/temporary_codes/merged.c"
    python3 "./src/crypters/code_obfuscation/crypter.py" -o ./src/crypters/code_obfuscation/temporary_codes/merged.c "${source_directory}${file}"
    python3 "./src/crypters/code_obfuscation/opaque_variables.py" ./src/crypters/code_obfuscation/temporary_codes/merged.c "./src/crypters/code_obfuscation/temporary_codes/transformed_merged.c"
    clang --target=i686-pc-windows-gnu -I "./src/crypters/code_obfuscation/fake_imports" -lkernel32 -O0 "./src/crypters/code_obfuscation/temporary_codes/transformed_merged.c" -o "${destination_directory}${file}"
    objcopy --strip-debug "${destination_directory}${file}"
done

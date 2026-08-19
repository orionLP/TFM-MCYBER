#!/bin/bash

destination_directory="./data/final_pipeline/"

echo "Deleting previous samples"
rm -rf "${destination_directory}*"

mkdir -p ${destination_directory}

seeds=(
  4f5cf32be20242cc5f17594b1e1d568f7e25585d98760179547730290f68e5032564262ac62f72e4da8270ba
  05c8df6d3b34027879a35875ee182ea01a8cc7a4f6ddb41557bb16b741d82a1310e0e33dcd47fba90870d338
)

echo "Creating reverse shell sample"

python3 ./src/final_pipeline/process_shell.py ./src/final_pipeline/shell_merged.c "./src/final_pipeline/windows_shell_reverse_tcp.c" "${destination_directory}windows_shell_reverse_tcp.exe" data/usable_headers/list_of_usable_headers.json "./data/raw/shellcode/x86/windows_shell_reverse_tcp.bin" "${seeds[0]}"

objcopy --strip-debug "${destination_directory}windows_shell_reverse_tcp.exe"
rm "./src/final_pipeline/windows_shell_reverse_tcp.c"  

echo "Create bind shell sample"

python3 ./src/final_pipeline/process_shell.py ./src/final_pipeline/shell_merged.c "./src/final_pipeline/windows_shell_bind_tcp.c" "${destination_directory}windows_shell_bind_tcp.exe" data/usable_headers/list_of_usable_headers.json "./data/raw/shellcode/x86/windows_shell_bind_tcp.bin" "${seeds[1]}"

objcopy --strip-debug "${destination_directory}windows_shell_bind_tcp.exe"
rm "./src/final_pipeline/windows_shell_bind_tcp.c"





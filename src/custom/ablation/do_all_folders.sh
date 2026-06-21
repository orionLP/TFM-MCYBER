#!/bin/bash

source_directories=(
    "./data/raw/exe/x86/"
    "./data/crypters/exe/x86/tutorial/"
    "./data/packed/exe/x86/mpress/"
    "./data/packed/exe/x86/petite/"
    "./data/packed/exe/x86/upx/default/"
    "./data/packed/exe/x86/upx/lzma/"
    "./data/crypters/exe/x86/code_obfuscation/opaque_ifs"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY3"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY3"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY3"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY3"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY3"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY1"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY2"
    "./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY3"
)
 
destination_directories=(
    "./data/custom/ablation/raw/"
    "./data/custom/ablation/tutorial/"
    "./data/custom/ablation/mpress/"
    "./data/custom/ablation/petite/"
    "./data/custom/ablation/upx/default/"
    "./data/custom/ablation/upx/lzma/"
    "./data/custom/ablation/code_obfuscation/opaque_ifs"
    "./data/custom/ablation/multiple_information_reveal/algo1/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo1/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo1/KEY3"
    "./data/custom/ablation/multiple_information_reveal/algo1_v2/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo1_v2/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo1_v2/KEY3"
    "./data/custom/ablation/multiple_information_reveal/algo1_v3/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo1_v3/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo1_v3/KEY3"
    "./data/custom/ablation/multiple_information_reveal/algo2/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo2/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo2/KEY3"
    "./data/custom/ablation/multiple_information_reveal/algo2_v2/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo2_v2/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo2_v2/KEY3"
    "./data/custom/ablation/multiple_information_reveal/algo2_v3/KEY1"
    "./data/custom/ablation/multiple_information_reveal/algo2_v3/KEY2"
    "./data/custom/ablation/multiple_information_reveal/algo2_v3/KEY3"
)

rm -rf "./data/custom/ablation/"

gcc ./src/custom/ablation/main.c ./src/custom/ablation/pe_file.c -o ./src/custom/ablation/ablation
executable="./src/custom/ablation/ablation"

if [ "${#source_directories[@]}" -ne "${#destination_directories[@]}" ]; then
    echo "error: lists have different lengths (${#source_directories[@]} vs ${#destination_directories[@]})"
    exit 1
fi

for i in "${!source_directories[@]}"; do
    mkdir -p "${destination_directories[$i]}"
    ${executable} "${source_directories[$i]}" "${destination_directories[$i]}"
done
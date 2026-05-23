#!/bin/bash

source_directories=(
    "./data/raw/exe/x86/"
    "./data/crypters/exe/x86/tutorial/"
    "./data/packed/exe/x86/mpress/"
    "./data/packed/exe/x86/petite/"
    "./data/packed/exe/x86/upx/default/"
    "./data/packed/exe/x86/upx/lzma/"
)

destination_directories=(
    "./data/custom/ablation/raw/"
    "./data/custom/ablation/tutorial/"
    "./data/custom/ablation/mpress/"
    "./data/custom/ablation/petite/"
    "./data/custom/ablation/upx/default/"
    "./data/custom/ablation/upx/lzma/"
)

gcc ./src/custom/ablation/main.c ./src/custom/ablation/pe_file.c -o ./src/custom/ablation/ablation
executable="./src/custom/ablation/ablation"

if [ "${#source_directories[@]}" -ne "${#destination_directories[@]}" ]; then
    echo "error: lists have different lengths (${#source_directories[@]} vs ${#destination_directories[@]})"
    exit 1
fi

for i in "${!source_directories[@]}"; do
    mkdir -p "${source_directories[$i]}"
    find "${source_directories[$i]}" -mindepth 1 -delete
    "$executable" "${source_directories[$i]}" "${destination_directories[$i]}"
done
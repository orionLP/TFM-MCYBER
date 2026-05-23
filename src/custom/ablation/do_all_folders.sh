#!/bin/bash

list1=(
    "/path/to/dir1"
    "/path/to/dir2"
    "/path/to/dir3"
)

list2=(
    "/path/to/other1"
    "/path/to/other2"
    "/path/to/other3"
)

executable="/path/to/your/executable"

if [ "${#list1[@]}" -ne "${#list2[@]}" ]; then
    echo "error: lists have different lengths (${#list1[@]} vs ${#list2[@]})"
    exit 1
fi

for i in "${!list1[@]}"; do
    mkdir -p "${list1[$i]}"
    find "${list1[$i]}" -mindepth 1 -delete
    "$executable" "${list1[$i]}" "${list2[$i]}"
done
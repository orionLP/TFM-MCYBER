#!/bin/bash

pack_upx(){
	target_directory=${1}
	source_directory=${2}
	source_filename=${3}

	strip "${source_directory}/${source_filename}" -o "${target_directory}/${source_filename}"

	if [ $# -eq "3" ]; then
		upx -qq "${target_directory}/${source_filename}"
	else
		compression_options=${4}
		upx -qq ${compression_options} "${target_directory}/${source_filename}"
	fi
}

pack_mpress(){
	target_directory=${1}
	source_directory=${2}
	source_filename=${3}

	cp "${source_directory}/${source_filename}" "${target_directory}/${source_filename}"
	wine ./software/mpress.exe -qq "${target_directory}/${source_filename}"
}

source_dir='data/raw/exe/x86'
target_dir='data/packed/exe/x86'
upx_dir="${target_dir}/upx"
mpress_dir="${target_dir}/mpress"

rm -rf "data/packed"
mkdir "data/packed"
mkdir -p "${upx_dir}"
mkdir -p "${upx_dir}/default"
mkdir -p "${upx_dir}/lzma"
mkdir -p "${mpress_dir}"

for file in $(ls ${source_dir}); do
	pack_upx "${upx_dir}/default" ${source_dir} ${file}
	pack_upx "${upx_dir}/lzma" ${source_dir} ${file} "--lzma"
	pack_mpress "${mpress_dir}" ${source_dir} ${file}
done

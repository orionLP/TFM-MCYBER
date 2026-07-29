#!/bin/bash

source_file="./data/raw/exe/x86/windows_meterpreter_reverse_tcp.exe" 
destination_directory="./data/custom/code_stop/crypters_idata_obfuscation_dynamic_api_resolution/"

mkdir -p ${destination_directory}

seeds=(
  bd2a4024c0af98f4cf1bef8204b1458f3a2f61d4fc8559f4307a086b7c8eb2ca63dea7107a3f2067d0b75077
  bd6637594765f689bce14e4d3012917d95ed3a1db0aa869b638e320ecaacce5ffad8fe64463396c001b9543d
  5e7457a21cf5a0523be9ef270f51143cca0d323bd2cb871d685a1c8710af542119856a43769934e49fcfdd70
  2e63f115c242eac2b89e4cafda68ebae2209cc87ce55edd05e0d8a30fbce4a6a78c9631f9c2250a4129efbdd
  c1fed1982bf7755655241dd2b271797b38824ff42d109779306cad72faaa24d67f55de85917409f9065aec45
  f2000c94f7d930e2349d74585ab5643e0d95d26f27ad0abab3b9fdaf20be1a8a82d6bdb2608d1699eaff461b
  e186bda3e02c800ea3754d2b075215d810909d6a4f3e97d8ed48c65ada0c1c11c27b0e6d760ba68c2af0fb55
  5763580905cd896b6a15a3f6143ceee6e2394923dee1238c2bdc323ced624942ec01b846bca3cc62c66935ac
  3e5bdebb462667ca83df3f4676be27efbcb6263e1e5f984634134136cb6f388943c58feb04f081a42f4ec550
  35cc9e7ea5c4bc4072c4765779db87f88afb50720e32870fc1963860ebca5bf39155b04d50887c1751f1c3de
  dc4685a206435cc15f3842d68522f95e099281ee5c22eeac1c05712f76fe3c1c24ecba702b85debf97fcaf0d
  f1a8c472b094ef67ffdf6dd923e21f34efa08adb6433b0808816876f706374d03fb8a916205ce8326aab0078
  494a121da76363be03e46044e7e605120a8d6c47affeef1fb63f31901c071a05d8fb2053e3334cde51467469
  81dbc2c08a6e85d15e79e43c584ccc0e431a26adb9d2e46ac9d686c61e3b1796c90ae2b2a647b9b5ca4bd366
  87ff624ad151f87ed89954fb9311f2ec8898f3d9ae54471e5d11b6b53b5abf4f76d16821ef17b792dab0151a
  01f17bdd471e04c7a3d92722ab503f61e79e8f776c6bf461378e82b2469589766f6ce8639b9a9ca9cc34eefc
  ab5632086454e3e9a22d31510d9cf4e62ef6315dcd5cbec01d4187caf842e39592b7c7816aef89123b395a1e
  19b5f574443da30f6f6b4cffff7365413e5acbf1090007d45942b04573968a3fbcd64424ecb045bc86934c49
  aa52790772422da6e76704249ce996c45c738dabc6868cd8a3017933bb34bf9e7162b1ea095f4504d1aed2e5
  364ebbbed28adee0e51760a5a326140bfcfc24cb3b67a49c7f681e06208d0f1427cb20a336cf218cd484ee9c
  686ef8c92917de883031afd76ba2f2c258cb55ee75f3d00ad4d0c0a4312fcd1b16f8b3c8c359fdd4881629b2
  6f2401f5c5b9e50ae56fac9c9b55f2027849320db2f7558fbbb1c124b820a466228197e22e150824b8e9264a
  8d27526d19da5c907c697c5b48c2c38675d89a006801f7ad99be70c7447fcbaa3f655c5e938e7aadefebae7d
  d32ac0f300d5a711f08b112182b2f55cd8050d41ddbd077969ef45d55a33a47809f780dea2134f6e303a5985
  eb2f091a116840b0f4f7dfb46dd27fc76fdb56d32227d5026bd3c384c2a514b10af68fc1b231fb4b36d16c21
  5f525b921b08743f1fed8e67583572aec6a633d305cc7f93de67481ecb02a5464716b05efdce291626d3ea09
  0d6a8017bc20639fe8ca22d7711a551c3e604692fc4b3dbc38ccda5825821e9a26606ab5f6c82f29d9bf0077
  f0b3668954e351050e0a93a13c492b667f70372adb5e15396f185370f27c22cf1aef02af748bcfd9d93c4279
  5dda5bf31869c3fb6e4c8e2fef6de51c7bf55002d7d8b9746d261da78987230a1bb77a2f51e9abedce3e579d
  90f01cb582b591819acaa2558a5c6870f5cc009f9e87a0f369e2d0561c07bdc79e29fb8b17c72c405ace50a7
)

for i in $(seq 0 9); do
	echo "Running iteration ${i} with seed ${seeds[${i}]}"

	python3 src/custom/code_stop/process.py src/custom/code_stop/first_stop_merged.c "./src/custom/code_stop/first_stop_output_${i}.c" "${destination_directory}first_stop_output_${i}.exe" "${source_file}" data/usable_headers/list_of_usable_headers.json "${seeds[${i}]}"

	objcopy --strip-debug "${destination_directory}first_stop_output_${i}.exe"
	rm "./src/custom/code_stop/first_stop_output_${i}.c"
done

for i in $(seq 10 19); do
	echo "Running iteration ${i} with seed ${seeds[${i}]}"

	python3 src/custom/code_stop/process.py src/custom/code_stop/second_stop_merged.c "./src/custom/code_stop/second_stop_output_${i}.c" "${destination_directory}second_stop_output_${i}.exe" "${source_file}" data/usable_headers/list_of_usable_headers.json "${seeds[${i}]}"

	objcopy --strip-debug "${destination_directory}second_stop_output_${i}.exe"
	rm "./src/custom/code_stop/second_stop_output_${i}.c"
done	

for i in $(seq 20 29); do
	echo "Running iteration ${i} with seed ${seeds[${i}]}"

	python3 src/custom/code_stop/process.py src/custom/code_stop/third_stop_merged.c "./src/custom/code_stop/third_stop_output_${i}.c" "${destination_directory}third_stop_output_${i}.exe" "${source_file}" data/usable_headers/list_of_usable_headers.json "${seeds[${i}]}"

	objcopy --strip-debug "${destination_directory}third_stop_output_${i}.exe"
	rm "./src/custom/code_stop/third_stop_output_${i}.c"
done	

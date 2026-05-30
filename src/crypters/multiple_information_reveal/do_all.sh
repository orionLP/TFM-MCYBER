#!/bin/bash

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo1_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v2.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3

clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY1.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY1
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY2.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY2
clang --target=i686-pc-windows-gnu ./src/crypters/multiple_information_reveal/decryption_algo2_v3.c ./src/crypters/multiple_information_reveal/malware_decryptor.c -o ./src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY3.exe  "-Wl,--entry=__start" -nostartfiles -nostdlib -lkernel32 -DKEY3



python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY1 --KEY 1 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY2 --KEY 2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1/KEY3 --KEY 3 ./data/raw/exe/x86

python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY1 --KEY 1 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY2 --KEY 2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v2_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v2/KEY3 --KEY 3 ./data/raw/exe/x86

python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY1 --KEY 1 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY2 --KEY 2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo1_v3_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo1_v3/KEY3 --KEY 3 ./data/raw/exe/x86


python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY1 --KEY 1 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY2 --KEY 2 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2/KEY3 --KEY 3 --algo2 ./data/raw/exe/x86

python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY1 --KEY 1 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY2 --KEY 2 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v2_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v2/KEY3 --KEY 3 --algo2 ./data/raw/exe/x86

python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY1.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY1 --KEY 1 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY2.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY2 --KEY 2 --algo2 ./data/raw/exe/x86
python3 src/crypters/multiple_information_reveal/crypter.py -p src/crypters/multiple_information_reveal/decrypter_algo2_v3_KEY3.exe -o ./data/crypters/exe/x86/multiple_information_reveal/algo2_v3/KEY3 --KEY 3 --algo2 ./data/raw/exe/x86
#!/bin/bash

# For now this is to just test the setup

for file in $(ls data/raw/exe/x86);
do
	strip "data/raw/exe/x86/${file}" -o "data/packed/upx/exe/x86/${file}";
	upx "data/packed/upx/exe/x86/${file}";
done


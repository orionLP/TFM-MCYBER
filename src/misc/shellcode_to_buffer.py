#!/usr/bin/env python3
"""Convert raw shellcode binary to C byte array."""

import sys
import argparse
from pathlib import Path


def bin_to_c_array(input_file, output_file=None, array_name="shellcode"):
    """Read binary shellcode and output as C byte array."""
    
    try:
        with open(input_file, 'rb') as f:
            data = f.read()
    except FileNotFoundError:
        print(f"Error: File '{input_file}' not found")
        sys.exit(1)
    except Exception as e:
        print(f"Error reading file: {e}")
        sys.exit(1)
    
    if not data:
        print("Error: File is empty")
        sys.exit(1)
    
    # Generate C array
    c_code = f"unsigned char {array_name}[] = \""
    
    # Format bytes: 16 per line, hex format
    for i, byte in enumerate(data):
        c_code += f"\\x{byte:02x}"
    c_code += f"\";\n"
    
    # Output
    if output_file:
        try:
            with open(output_file, 'w') as f:
                f.write(c_code)
            print(f"[+] Wrote C array to '{output_file}'")
            print(f"[+] Shellcode size: {len(data)} bytes")
        except Exception as e:
            print(f"Error writing output: {e}")
            sys.exit(1)
    else:
        print(c_code)
        print(f"// Shellcode size: {len(data)} bytes")


if __name__ == "__main__":
    parser = argparse.ArgumentParser(
        description="Convert raw shellcode binary to C byte array"
    )
    parser.add_argument("input", help="Input binary shellcode file")
    parser.add_argument(
        "-o", "--output",
        help="Output C file (if not specified, prints to stdout)"
    )
    parser.add_argument(
        "-n", "--name",
        default="shellcode",
        help="C array name (default: shellcode)"
    )
    
    args = parser.parse_args()
    bin_to_c_array(args.input, args.output, args.name)

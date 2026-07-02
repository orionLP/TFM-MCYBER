import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.obfuscation.utils.scope as scope
import src.lib.obfuscation.control.opaqueif as opaqueif
import src.lib.obfuscation.control.opaquevariable as op
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.visitors.opaqueifvisitor as opaqueifvisitor
import src.lib.obfuscation.visitors.opaquevariablevisitor as opaquevariablevisitor

from src.lib.crypto.rng import prng
from pycparser import c_generator

import pycparser
import secrets
import sys

if __name__ == '__main__':
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <input.c> <output.c> [seed]")
        sys.exit(1)

    input_file  = sys.argv[1]
    output_file = sys.argv[2]
    seed = None
    if len(sys.argv) == 4:
        print('Using selected seed')
        seed = sys.argv[3]
        key = seed[:prng.key_length * 2]
        nonce = seed[prng.key_length * 2: (prng.key_length + prng.nonce_length) * 2]
        prng.key = bytes.fromhex(key)
        prng.nonce = bytes.fromhex(nonce)
    else:
        print("No seed was given, using a random seed")

    ast = pycparser.parse_file(
        input_file,
        use_cpp=True,
        cpp_path='cpp',
        cpp_args=['-I./src/fake_imports']
    )

    gen = pycparser.c_generator.CGenerator()
    result = gen.visit(ast)

    with open(output_file, 'w') as f:
        f.write(result)
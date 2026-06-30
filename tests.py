import src.lib.obfuscation.control.opaquevariable as op
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.ctypes as ctypes
import src.lib.obfuscation.utils.namegenerator as namegenerator

from pycparser import c_generator
from src.lib.crypto.rng import prng

import secrets

key = b'\x89\xbc6\x8a[\xd3u\xb1\xb7\xc4\xf8\xb8\xdd\xf2\xef\xea\xbc\xaf\xca\xb0>\xd8\xf3\xe8\x0f,\xf6\x17:\xd9V\x8f'
nonce = b'\xbcj}v\xadL\xf0\xf0\xd4\xef\xe5!'

prng.key = key
prng.nonce = nonce
prng.commit_changes()

generator = c_generator.CGenerator()

print('\nResidueTrueOpaqueVariable\n')

rtov = op.ResidueTrueOpaqueVariable(
    ctypes.I686PCWindowsGNU, 
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
    cbuilder.StandardFrequentCodeCBuilder(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), ctypes.I686PCWindowsGNU), 
    namegenerator.StandardVariableNameGenerator(16)
)
rtov_nodes = rtov.generate_opaque_variable(ctypes.CTypes.UNSIGNED_INT)

for node in rtov_nodes:
    print(generator.visit(node))

print('\nRAPrimeOpaqueVariable\n')

rapov = op.RAPrimeOpaqueVariable(
    ctypes.I686PCWindowsGNU, 
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
    cbuilder.StandardFrequentCodeCBuilder(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), ctypes.I686PCWindowsGNU), 
    namegenerator.StandardVariableNameGenerator(16)
)

rapov_nodes = rapov.generate_opaque_variable(ctypes.CTypes.UNSIGNED_INT)

for node in rapov_nodes:
    print(generator.visit(node))

print('\nAddressRandomOpaqueVariable\n')

arov = op.AddressRandomOpaqueVariable(
    ctypes.I686PCWindowsGNU, 
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
    cbuilder.StandardFrequentCodeCBuilder(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), ctypes.I686PCWindowsGNU), 
    namegenerator.StandardVariableNameGenerator(16)
)

arov_nodes = arov.generate_opaque_variable(ctypes.CTypes.UNSIGNED_INT)

for node in arov_nodes:
    print(generator.visit(node))
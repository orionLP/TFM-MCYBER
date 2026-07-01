import src.lib.obfuscation.control.opaquevariable as op
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.ctypes as ctypes
import src.lib.obfuscation.utils.namegenerator as namegenerator
import src.lib.obfuscation.control.opaquepredicate as opaquepredicate
import src.lib.obfuscation.control.opaqueif as opaqueif
import src.lib.obfuscation.visitors.opaqueifvisitor as opaqueifvisitor
import src.lib.obfuscation.visitors.opaquevariablevisitor as opaquevariablevisitor

import src.lib.obfuscation.utils.scope as scope

from pycparser import c_generator
from src.lib.crypto.rng import prng

import secrets

key = b'\x80\xbc6\x8a[\xd3u\xb1\xb7\xc4\xf8\xb8\xdd\xf2\xef\xea\xbc\xaf\xca\xb0>\xd8\xf3\xe8\x0f,\xf6\x17:\xd9V\x8f'
nonce = b'\xbcj}v\xadL\xf0\xf0\xd4\xef\x19!'

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

print('\nIsOddOrTwoPredicateTemplate\n')

iootpt = opaquepredicate.IsOddOrTwoOpaquePredicate(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
)

iootpt_nodes = [iootpt.create_predicate(['v6356d40cdf4563ebe31b543c4f9bc8f0_prime_opaque'], ctypes.CTypes.UNSIGNED_INT)]

for node in iootpt_nodes:
    print(generator.visit(node))

print('\nPythagoreanTriplePredicateTemplate\n')

ptpt = opaquepredicate.PythagoreanTripleOpaquePredicate(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
)

ptpt_nodes = [ptpt.create_predicate(['vde3a5852e9ee86b89bb50b79ef143a09_random_opaque'], ctypes.CTypes.UNSIGNED_INT)]

for node in ptpt_nodes:
    print(generator.visit(node))

print('\nDummyOpaquePredicate\n')

top = opaquepredicate.DummyOpaquePredicate(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
)

top_nodes = [top.create_predicate(['vf4128ee24a084c6b102476805b91797a_true_opaque'], ctypes.CTypes.UNSIGNED_INT)]

for node in top_nodes:
    print(generator.visit(node))

print('\ndefined_variables_to_line\n')

created_block = cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU).block(rapov_nodes)

# print(created_block)
# print(scope.defined_variables_to_line(created_block,5))

print('\nJunkOpaqueIf\n')

joi = opaqueif.JunkOpaqueIf(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
)

empty_scope = scope.StandardScope()
empty_scope.enter_block()

newblock = cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU).block(rapov_nodes)
joi.use_opaque_if(empty_scope, top_nodes[0], newblock)

for node in newblock:
    print(generator.visit(node))

print('\nBogusFlowOpaqueIf\n')

bfoi = opaqueif.BogusFlowOpaqueIf(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
)

empty_scope = scope.StandardScope()
empty_scope.enter_block()

newblock = cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU).block(rapov_nodes)
bfoi.use_opaque_if(empty_scope, top_nodes[0], newblock)

for node in newblock:
    print(generator.visit(node))

print('\nTrueOpaqueIfVisitor InjectOpaqueVariableVisitor\n')

iovv = opaquevariablevisitor.InjectOpaqueVariableVisitor(
    cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU),
    op.ResidueTrueOpaqueVariable(
        ctypes.I686PCWindowsGNU, 
        cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
        cbuilder.StandardFrequentCodeCBuilder(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), ctypes.I686PCWindowsGNU), 
        namegenerator.StandardVariableNameGenerator(16)
    ),
    ctypes.CTypes.UNSIGNED_INT,
    scope.StandardScope(),
    16,
    1
)

newblock = cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU).block(rapov_nodes)

print('Original: ')
print(generator.visit(newblock))
iovv.visit(newblock)

print("With variables")
print(generator.visit(newblock))

toiv = opaqueifvisitor.TrueOpaqueIfVisitor(
    opaquepredicate.DummyOpaquePredicate(
        cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), 
    ),
    opaqueif.JunkOpaqueIf(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU)),
    ctypes.CTypes.UNSIGNED_INT,
    scope.StandardScope(),
    16
)
toiv.visit(newblock)


print("With toiv")
print(generator.visit(newblock))


# toiv.visit(newblock)

# for node in newblock:
#     print(generator.visit(node))
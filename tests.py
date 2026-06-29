import src.lib.obfuscation.control.opaquevariable as op
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.ctypes as ctypes
import src.lib.obfuscation.utils.namegenerator as namegenerator
from pycparser import c_generator

generator = c_generator.CGenerator()

rtov = op.ResidueTrueOpaqueVariable(ctypes.I686PCWindowsGNU , cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), cbuilder.StandardFrequentCodeCBuilder(cbuilder.StandardCBuilder(ctypes.I686PCWindowsGNU), ctypes.I686PCWindowsGNU), namegenerator.StandardVariableNameGenerator(16))
rtov_nodes = rtov.generate_opaque_variable(ctypes.CTypes.UNSIGNED_INT)

for node in rtov_nodes:
    print(generator.visit(node))

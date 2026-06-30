import abc
import pycparser

from src.lib.crypto.rng import prng

import src.lib.chandling.ctypes as ctypes
import src.lib.chandling.cbuilder as cbuilder
import src.lib.chandling.coperators as coperators
import src.lib.obfuscation.utils.namegenerator as namegenerator

class OpaqueIf(abc.ABC):

    def __init__(self, predicate: PredicateTemplate)
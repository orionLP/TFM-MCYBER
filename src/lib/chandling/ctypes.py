import enum
import dataclasses
from typing import Optional

'''Utilities related to pycparser types'''

class CTypes(enum.StrEnum):
    UNSIGNED_INT = 'unsigned_int'
    INT = 'int'
    UNSIGNED_SHORT = 'unsigned_short'
    SHORT = 'short'
    UNSIGNED_CHAR = 'unsigned_char'
    CHAR = 'char'
    UNSIGNED_LONG = 'unsigned_long'
    LONG = 'long'
    UNSIGNED_LONG_LONG = 'unsigned_long_long'
    LONG_LONG = 'long_long'
    FLOAT = 'float'
    DOUBLE = 'double'
    VOID = 'void'

class DerivedCTypes(enum.StrEnum):
    ARRAY = 'array'
    POINTER = 'pointer'
    FUNCTION = 'function'

class UserDefinedTypes(enum.StrEnum):
    UNION = 'union'
    STRUCT = 'struct'
    ENUM = 'enum'

@dataclasses.dataclass
class CTypeInfo():
    cname: str
    cname_list: list[str]
    min_value: Optional[int] | None
    max_value: Optional[int] | None
    size: int | None

@dataclasses.dataclass
class CTypeTable():
    unsigned_int: CTypeInfo
    int: CTypeInfo
    unsigned_short: CTypeInfo
    short: CTypeInfo
    unsigned_char: CTypeInfo
    char: CTypeInfo
    unsigned_long: CTypeInfo
    long: CTypeInfo
    unsigned_long_long: CTypeInfo
    long_long: CTypeInfo
    float: CTypeInfo
    double: CTypeInfo
    void: CTypeInfo
    pointer: CTypeInfo
    
    def __getitem__(self, ctype: CTypes | DerivedCTypes) -> CTypeInfo:
        return getattr(self, ctype.value)

# i686 (32-bit) Windows with MinGW GNU toolchain
I686PCWindowsGNU: CTypeTable = CTypeTable(
    unsigned_int=CTypeInfo('unsigned int', ['unsigned', 'int'], 0, 2**32 - 1, 4),
    int=CTypeInfo('int', ['int'], -(2**31), 2**31 - 1, 4),
    unsigned_short=CTypeInfo('unsigned short', ['unsigned', 'short'], 0, 2**16 - 1, 2),
    short=CTypeInfo('short', ['short'], -(2**15), 2**15 - 1, 2),
    unsigned_char=CTypeInfo('unsigned char', ['unsigned', 'char'], 0, 2**8 - 1, 1),
    char=CTypeInfo('char', ['char'], -(2**7), 2**7 - 1, 1),
    unsigned_long=CTypeInfo('unsigned long', ['unsigned', 'long'], 0, 2**32 - 1, 4),
    long=CTypeInfo('long', ['long'], -(2**31), 2**31 - 1, 4),
    unsigned_long_long=CTypeInfo('unsigned long long', ['unsigned', 'long', 'long'], 0, 2**64 - 1, 8),
    long_long=CTypeInfo('long long', ['long', 'long'], -(2**63), 2**63 - 1, 8),
    float=CTypeInfo('float', ['float'], None, None, 4),
    double=CTypeInfo('double', ['double'], None, None, 8),
    void=CTypeInfo('void', ['void'], None, None, 0),
    pointer=CTypeInfo('pointer',['pointer'], 0, 2**32 - 1, 4)
)
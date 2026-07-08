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

def corresponding_ctype(info_table: CTypeInfo, cname_list: list[str]) -> CTypes:
    for item in info_table:
        if cname_list == info_table.cname_list:
            return info_table.enum_instance
    raise Exception("Ctype not found")
    
def is_primitive(c_type: CTypes | DerivedCTypes) -> bool:
    if c_type in CTypes:
        return True
    return c_type == DerivedCTypes.POINTER

@dataclasses.dataclass
class CTypeInfo():
    cname: str
    cname_list: list[str]
    min_value: Optional[int] | None
    max_value: Optional[int] | None
    size: int | None
    enum_instance: CTypes | DerivedCTypes | UserDefinedTypes

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

    def __iter__(self):
        for ctype in CTypes:
            yield self[ctype]
        yield self[DerivedCTypes.POINTER]

# i686 (32-bit) Windows with MinGW GNU toolchain
I686PCWindowsGNU: CTypeTable = CTypeTable(
    unsigned_int=CTypeInfo('unsigned int', ['unsigned', 'int'], 0, 2**32 - 1, 4, CTypes.UNSIGNED_INT),
    int=CTypeInfo('int', ['int'], -(2**31), 2**31 - 1, 4, CTypes.INT),
    unsigned_short=CTypeInfo('unsigned short', ['unsigned', 'short'], 0, 2**16 - 1, 2, CTypes.UNSIGNED_SHORT),
    short=CTypeInfo('short', ['short'], -(2**15), 2**15 - 1, 2, CTypes.SHORT),
    unsigned_char=CTypeInfo('unsigned char', ['unsigned', 'char'], 0, 2**8 - 1, 1, CTypes.UNSIGNED_CHAR),
    char=CTypeInfo('char', ['char'], -(2**7), 2**7 - 1, 1, CTypes.CHAR),
    unsigned_long=CTypeInfo('unsigned long', ['unsigned', 'long'], 0, 2**32 - 1, 4, CTypes.UNSIGNED_LONG),
    long=CTypeInfo('long', ['long'], -(2**31), 2**31 - 1, 4, CTypes.LONG),
    unsigned_long_long=CTypeInfo('unsigned long long', ['unsigned', 'long', 'long'], 0, 2**64 - 1, 8, CTypes.UNSIGNED_LONG_LONG),
    long_long=CTypeInfo('long long', ['long', 'long'], -(2**63), 2**63 - 1, 8, CTypes.LONG_LONG),
    float=CTypeInfo('float', ['float'], None, None, 4, CTypes.FLOAT),
    double=CTypeInfo('double', ['double'], None, None, 8, CTypes.DOUBLE),
    void=CTypeInfo('void', ['void'], None, None, 0, CTypes.VOID),
    pointer=CTypeInfo('pointer',['void *'], 0, 2**32 - 1, 4, DerivedCTypes.POINTER)
)
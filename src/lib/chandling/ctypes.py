import enum
import dataclasses

class CTypes(enum.StrEnum):
    UNSIGNED_INT = 'unsigned_int'
    INT = 'int'

@dataclasses.dataclass
class CTypeInfo():
    cname: str
    cname_list: list[str]
    min_value: int
    max_value: int

@dataclasses.dataclass
class CTypeTable():
    unsigned_int: CTypeInfo
    int: CTypeInfo

    def __getitem__(self, ctype: CTypes) -> CTypeInfo:
        return getattr(self, ctype.value)

I686PCWindowsGNU: CTypeTable = CTypeTable(
    CTypeInfo('unsigned int', ['unsigned', 'int'], 0, 2**32 - 1),
    CTypeInfo('int', ['int'], -(2**31), 2**31 - 1)
)

import enum
import dataclasses

@dataclasses.dataclass
class CTypeInfo():
    cname: str
    min_value: int
    max_value: int

@dataclasses.dataclass
class CTypeTable():
    unsigned_int: CTypeInfo
    int: CTypeInfo

I686PCWindowsGNU: CTypeTable = CTypeTable(
    CTypeInfo('unsigned int', 0, 2**32 - 1),
    CTypeInfo('int', -(2**31), 2**31 - 1)
)

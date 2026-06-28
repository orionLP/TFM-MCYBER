import enum
import dataclasses


@dataclasses.dataclass
class CTypeInfo:
    cname: str
    min_value: int
    max_value: int

class CTypei6WindowsGNU(Enum):
# Values hardcoded for i686-pc-windows-gnu
    UNSIGNED_INT = CTypeInfo('unsigned int', 0, 2**32 - 1)
    INT = CTypeInfo('int', -(2**31), 2**31 - 1)

    @property
    def cname(self):   
        return self.value.cname
    
    @property
    def min_val(self): 
        return self.value.min_val
    
    @property
    def max_val(self): 
        return self.value.max_val
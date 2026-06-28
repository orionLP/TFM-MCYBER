from dataclasses import dataclass

@dataclass
class CTypeInfo:
    cname: str
    min_val: int
    max_val: int
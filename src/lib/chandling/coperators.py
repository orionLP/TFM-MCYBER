import enum
import dataclasses

@dataclasses.dataclass
class Operator():
    pycparser_string: str

class BinaryCOperator(enum.StrEnum):
    ADDITION = Operator('+')
    SUBTRACTION = Operator('-')
    DIVISION = Operator('/')
    MULTIPLICATION = Operator('*')
    MODULO = Operator('%')

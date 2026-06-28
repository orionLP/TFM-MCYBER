import enum
import dataclasses

@dataclasses.dataclass
class Operator():
    pycparser_string: str

class AssignmentCOperator(enum.Enum):
    ASSIGNMENT = Operator('=')

class UnaryCOperator(enum.Enum):
    ADDRESS = Operator('&')
    DEREFERENCE = Operator('*')

class BinaryCOperator(enum.Enum):
    ADDITION = Operator('+')
    SUBTRACTION = Operator('-')
    DIVISION = Operator('/')
    MULTIPLICATION = Operator('*')
    MODULO = Operator('%')

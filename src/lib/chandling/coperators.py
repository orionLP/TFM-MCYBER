import enum
import dataclasses

@dataclasses.dataclass
class Operator():
    pycparser_string: str

class AssignmentCOperator(enum.Enum):
    ASSIGNMENT = Operator('=')
    ADDITIVEASSIGNMENT = Operator('+=')

class UnaryCOperator(enum.Enum):
    ADDRESS = Operator('&')
    DEREFERENCE = Operator('*')

class BinaryCOperator(enum.Enum):
    ADDITION = Operator('+')
    SUBTRACTION = Operator('-')
    DIVISION = Operator('/')
    MULTIPLICATION = Operator('*')
    MODULO = Operator('%')
    EQUAL = Operator('==')
    NOTEQUAL = Operator('!=')
    LESS = Operator('<')
    LESSOREQUAL = Operator('<=')
    OR = Operator('||')
    BITWISEOR = Operator('|')

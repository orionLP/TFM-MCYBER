import pycparser
import src.lib.chandling.ctypes as ctypes 

def corresponding_primitive(node: pycparser.c_ast.Node, info_table: ctypes.CTypeTable) -> ctypes.CTypes | ctypes.DerivedCTypes | None:
    if isinstance(node, pycparser.c_ast.TypeDecl) and isinstance(node.type, pycparser.c_ast.IdentifierType):
        for item in info_table:
            if item.cname_list == node.type.names:
                return item
    if is_pointer(node):
        return info_table[ctypes.DerivedCTypes.POINTER]
    return None

def is_function_declaration(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node.type, pycparser.c_ast.FuncDecl) and isinstance(node, pycparser.c_ast.Decl)

def is_type_identifier(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.IdentifierType)

def is_struct(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Struct)

def is_enum(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Enum)

def is_union(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Union)

def is_decl(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Decl)

def is_typedef(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.Typedef)

def is_pointer(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node, pycparser.c_ast.PtrDecl)

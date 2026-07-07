import pycparser
import src.lib.chandling.ctypes as ctypes 

def is_primitive(node: pycparser.c_ast.Node, info_table: ctypes.CTypeTable) -> ctypes.CTypes | ctypes.DerivedCTypes | None:
    if isinstance(node, pycparser.c_ast.IdentifierType):
        for item in info_table:
            if item.cname_list == node.names:
                return item
    return None

def is_function_declaration(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node.type, pycparser.c_ast.FuncDecl) and isinstance(node, pycparser.c_ast.Decl)

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
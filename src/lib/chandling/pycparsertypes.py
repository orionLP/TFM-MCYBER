import pycparser

def is_function_declaration(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node.type, pycparser.c_ast.FuncDecl) and isinstance(node, pycparser.c_ast.Decl)

def is_struct(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node.type, pycparser.c_ast.Struct)

def is_enum(node: pycparser.c_ast.Node) -> bool:
    return isinstance(node.type, pycparser.c_ast.Enum)
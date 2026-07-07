import clang

import src.lib.chandling.ctypes as ctypes

from clang.cindex import CursorKind, TypeKind

BUILTIN_KINDS = {
    TypeKind.VOID, 
    TypeKind.BOOL, 
    TypeKind.CHAR_U, 
    TypeKind.UCHAR, 
    TypeKind.USHORT, 
    TypeKind.UINT, 
    TypeKind.ULONG, 
    TypeKind.ULONGLONG, 
    TypeKind.CHAR_S, 
    TypeKind.SCHAR, 
    TypeKind.WCHAR, 
    TypeKind.SHORT, 
    TypeKind.INT,
    TypeKind.LONG, 
    TypeKind.LONGLONG, 
    TypeKind.INT128, 
    TypeKind.FLOAT, 
    TypeKind.DOUBLE, 
    TypeKind.LONGDOUBLE,
    TypeKind.NULLPTR,
    TypeKind.POINTER
}

CLANG_TO_CUSTOM = {
    TypeKind.VOID: ctypes.CTypes.VOID, 
    TypeKind.CHAR_U: ctypes.CTypes.UNSIGNED_CHAR, 
    TypeKind.UCHAR: ctypes.CTypes.UNSIGNED_CHAR, 
    TypeKind.USHORT: ctypes.CTypes.UNSIGNED_SHORT, 
    TypeKind.UINT: ctypes.CTypes.UNSIGNED_INT, 
    TypeKind.ULONG: ctypes.CTypes.UNSIGNED_LONG, 
    TypeKind.ULONGLONG: ctypes.CTypes.UNSIGNED_LONG_LONG, 
    TypeKind.CHAR_S: ctypes.CTypes.CHAR, 
    TypeKind.SCHAR: ctypes.CTypes.CHAR, 
    TypeKind.SHORT: ctypes.CTypes.SHORT, 
    TypeKind.INT: ctypes.CTypes.INT,
    TypeKind.LONG: ctypes.CTypes.LONG, 
    TypeKind.LONGLONG: ctypes.CTypes.LONG_LONG, 
    TypeKind.FLOAT: ctypes.CTypes.FLOAT, 
    TypeKind.DOUBLE: ctypes.CTypes.DOUBLE,
    TypeKind.POINTER: ctypes.DerivedCTypes.POINTER
}


# TODO: i think the type hint is wrong
def is_primitive(cursor: clang.cindex.Cursor) -> bool:
    return cursor in BUILTIN_KINDS

def is_function_declaration(cursor: clang.cindex.Cursor) -> bool:
    return cursor.kind == CursorKind.FUNCTION_DECL and not cursor.is_definition()

import clang

BUILTIN_KINDS = {
    TypeKind.VOID, TypeKind.BOOL, TypeKind.CHAR_U, TypeKind.UCHAR, TypeKind.CHAR16, TypeKind.CHAR32,
    TypeKind.USHORT, TypeKind.UINT, TypeKind.ULONG, TypeKind.ULONGLONG, TypeKind.UINT128,
    TypeKind.CHAR_S, TypeKind.SCHAR, TypeKind.WCHAR, TypeKind.SHORT, TypeKind.INT, TypeKind.LONG, 
    TypeKind.LONGLONG, TypeKind.INT128, TypeKind.FLOAT, TypeKind.DOUBLE, TypeKind.LONGDOUBLE,
    TypeKind.NULLPTR,
}

def is_primitive(cursor: clang.cindex.Cursor) -> bool:
    return cursor in BUILTIN_KINDS

def is_function_declaration(cursor: clang.cindex.Cursor) -> bool:
    return cursor.kind == CursorKind.FUNCTION_DECL and not cursor.is_definition()

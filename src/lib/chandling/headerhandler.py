import abc
import networkx as nx

from clang.cindex import CursorKind, TypeKind

class HeaderHandler(abc.ABC):

    @abc.abstractmethod
    def print_code(graph: nx.DiGraph) -> tuple[str,str]:
        '''
        The first string is the one from clang, the second one a variation that pycparser will understand
        '''
    
class StandardHeaderResolver(HeaderHandler):

    def _get_source_text(self, cursor) -> str:
        extent = cursor.extent
        start = extent.start.offset
 
        filename = extent.start.file.name
        with open(filename, 'rb') as f:
            content = f.read()
 
        i = start
        depth = 0  # Track { } and ( ) nesting
        in_string = False
        in_char = False
        escape_next = False
        
        while i < len(content):
            char = chr(content[i])
            
            if escape_next:
                escape_next = False
                i += 1
                continue
            
            if char == '\\' and (in_string or in_char):
                escape_next = True
                i += 1
                continue
            
            if char == '"' and not in_char:
                in_string = not in_string
                i += 1
                continue
            
            if char == "'" and not in_string:
                in_char = not in_char
                i += 1
                continue
            
            if not in_string and not in_char:
                if char in '({':
                    depth += 1
                elif char in ')}':
                    depth -= 1
                
                if char == ';' and depth == 0:
                    return content[start:i+1].decode('utf-8', errors='replace')
            
            i += 1
        
        raise Exception("The function StandardHeaderResolver._get_source_text should have never reached this point")
        
    def _sort_dependencies(self, graph: nx.DiGraph) -> list[str]:
        return list(reversed(list(nx.topological_sort(graph))))

    def _strip_attributes(self, text: str) -> str:
        out = []
        i = 0
        kw = "__attribute__"
        while i < len(text):
            if text.startswith(kw, i):
                j = i + len(kw)
                while j < len(text) and text[j].isspace():
                    j += 1
                if j < len(text) and text[j] == '(':
                    depth = 0
                    while j < len(text):
                        if text[j] == '(':
                            depth += 1
                        elif text[j] == ')':
                            depth -= 1
                            if depth == 0:
                                j += 1
                                break
                        j += 1
                    i = j
                    continue
            out.append(text[i])
            i += 1
        return ''.join(out)

    def _is_typedef_struct(self, graph: nx.DiGraph, resource: str) -> bool:
        parents = list(graph.predecessors(resource))
        enough_parents = len(parents) >= 1
        all_parents_are_typedef = True
        for parent_item in parents:
            all_parents_are_typedef = all_parents_are_typedef and CursorKind.TYPEDEF_DECL == graph.nodes[parent_item]['cursor'].kind

        return enough_parents and all_parents_are_typedef and CursorKind.STRUCT_DECL == graph.nodes[resource]['cursor'].kind

    def _is_typdef_enum(self, graph: nx.DiGraph, resource: str) -> bool:
        parents = list(graph.predecessors(resource))
        enough_parents = len(parents) >= 1
        all_parents_are_typedef = True
        for parent_item in parents:
            all_parents_are_typedef = all_parents_are_typedef and CursorKind.TYPEDEF_DECL == graph.nodes[parents[0]]['cursor'].kind
        return enough_parents and all_parents_are_typedef and CursorKind.ENUM_DECL == graph.nodes[resource]['cursor'].kind

    def print_code(self, graph: nx.DiGraph) -> tuple[str,str]:
        final_string = ""
        topological_sort = self._sort_dependencies(graph)
        for resource in topological_sort:
            node = graph.nodes[resource]['cursor']
            if not self._is_typedef_struct(graph, resource) and not self._is_typdef_enum(graph, resource):
                final_string += self._get_source_text(node)
                final_string += "\n"

        return (final_string, self._strip_attributes(final_string))

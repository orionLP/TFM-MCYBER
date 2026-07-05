import abc
import networkx as nx

from clang.cindex import CursorKind

class HeaderHandler(abc.ABC):

    @abc.abstractmethod
    def print_code(graph: nx.DiGraph) -> tuple[str,str]:
        '''
        The first string is the one from clang, the second one a variation that pycparser will understand
        '''
    
class StandardHeaderResolver(HeaderHandler):

    def _get_source_text(self, cursor) -> str:
        extent = cursor.extent
        print(extent)
        print([token for token in cursor.get_tokens()])
        print(cursor.spelling)
        start = extent.start.offset

        filename = extent.start.file.name
        with open(filename, 'rb') as f:
            content = f.read()

        # for some reason for typedefs libclang refuses to work
        if cursor.kind == CursorKind.TYPEDEF_DECL:
            end = content.find(b';', start)
        else:
            end = extent.end.offset
        
        return content[start:end].decode('utf-8')
        
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

    def print_code(self, graph: nx.DiGraph) -> tuple[str,str]:
        final_string = ""
        topological_sort = self._sort_dependencies(graph)
        print(topological_sort)
        for resource in topological_sort:
            print(graph.nodes[resource]['cursor'])
            node = graph.nodes[resource]['cursor']
            final_string += self._get_source_text(node)
            final_string += ";\n"

        return (final_string, self._strip_attributes(final_string))

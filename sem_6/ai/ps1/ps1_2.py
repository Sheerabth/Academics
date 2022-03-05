from gettext import find
from graph import Graph
from typing import List, Set, Union


class AStar:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self.heuristic = dict()

    def calculate_heuristic(self, start: int, end: int) -> Union[None, int]:
        if start in self.heuristic:
            return self.heuristic[start]

        if start == end:
            self.heuristic[start] = 0
            return self.heuristic[start]

        if start not in self.graph.adj_list:
            self.heuristic[start] = None
            return None
        
        distances = list()
        for neighbour in self.graph.adj_list[start]:
            result = self.calculate_heuristic(neighbour, end)
            if result is not None:
                distances.append(self.heuristic[neighbour])

        self.heuristic[start] = min(distances) + 1
        return self.heuristic[start]

    def find(self, start: int, end: int, distance: int = 0, path: List = list()) -> List[int]:
        path.append(start)
        if start == end:
            return path

        next_node = 
        for neighbour in self.adj_list[start]:
            result = min([find()])
            if result is not None:
                return result
        path.pop()
        return None


if __name__ == "__main__":
    g = Graph()
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 3)
    g.addEdge(2, 5)
    g.addEdge(5, 3)
    g.addEdge(3, 4)
    a_star = AStar(g)
    a_star.calculate_heuristic(0, 4)
    print(a_star.heuristic)
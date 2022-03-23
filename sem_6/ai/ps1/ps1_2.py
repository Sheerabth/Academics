from graph import Graph
from typing import List, Union


class AStar:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self.cost = dict()
        self.heuristic = dict()

    def calculate_utility(self, start: int, end: int) -> None:
        self.calculate_cost(start, end)
        self.calculate_heuristic(start, end)

    def calculate_cost(self, start: int, end: int, distance: int = 0) -> None:
        self.cost[start] = distance

        if start == end or start not in self.graph.adj_list:
            return

        for neighbour in self.graph.adj_list[start]:
            self.calculate_cost(neighbour, end, distance + 1)


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

        if len(distances) == 0:
            self.heuristic[start] = None
            return None

        self.heuristic[start] = min(distances) + 1
        return self.heuristic[start]
 

    def find(self, start: int, end: int) -> List[int]:
        self.calculate_heuristic(start, end)
        path = list()
        path.append(start)
        current_node = start

        while current_node != end:
            neighbours_heuristic = {key: value for (key, value) in self.heuristic.items() if key in self.graph.adj_list[current_node] and value is not None}
            neighbours_utility = {key: value + self.cost[key] for (key, value) in neighbours_heuristic.items()}
            current_node = min(neighbours_utility, key=neighbours_utility.get)
            path.append(current_node)

        return path


class HillClimbing:
    def __init__(self, graph: Graph) -> None:
        self.graph = graph
        self.utility = dict()

    
    def calculate_utility(self, start: int, end: int) -> Union[None, int]:
        if start in self.utility:
            return self.utility[start]

        if start == end:
            self.utility[start] = 0
            return self.utility[start]

        if start not in self.graph.adj_list:
            self.utility[start] = None
            return None
        
        distances = list()
        for neighbour in self.graph.adj_list[start]:
            result = self.calculate_utility(neighbour, end)
            if result is not None:
                distances.append(self.utility[neighbour])

        if len(distances) == 0:
            self.utility[start] = None
            return None

        self.utility[start] = min(distances) + 1
        return self.utility[start]

    def find(self, start: int, end: int) -> List[int]:
        self.calculate_utility(start, end)
        path = list()
        path.append(start)
        current_node = start

        while current_node != end:
            neighbours_utility = {key: value for (key, value) in self.utility.items() if key in self.graph.adj_list[current_node] and value is not None}
            current_node = min(neighbours_utility, key=neighbours_utility.get)
            path.append(current_node)

        return path


if __name__ == "__main__":
    g = Graph()
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 7)
    g.addEdge(2, 5)
    g.addEdge(5, 3)
    g.addEdge(3, 4)

    print("A Star")
    a_star = AStar(g)
    a_star.calculate_utility(0, 4)
    print(a_star.heuristic)
    print(a_star.cost)
    print(a_star.find(0, 4))

    print("Hill Climbing")
    hill_climbing = HillClimbing(g)
    hill_climbing.calculate_utility(0, 4)
    print(hill_climbing.utility)
    print(hill_climbing.find(0, 4))
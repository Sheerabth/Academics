import networkx as nx
import matplotlib.pyplot as plt
from collections import deque


class Graph:
    def __init__(self):
        self.graph = dict()
        self.edges = list()

    def addEdge(self, start, end):
        if (start, end) not in self.edges:
            self.edges.append((start, end))

        if start not in self.graph:
            self.graph[start] = list()

        self.graph[start].append(end)

    def dfs(self, start, end):
        path = list()
        path.append(start)

        if start == end:
            return True

        visited = set()
        stack = deque()

        visited.add(start)
        stack.append(start)

        while len(stack) != 0:
            start = stack.pop()

            if start in self.graph:
                for node in self.graph[start]:
                    if node not in visited:
                        path.append(node)
                        if node == end:
                            self.visualize(path)
                            return
                        visited.add(node)
                        stack.append(node)

            elif start in path:
                path.remove(start)

        self.visualize([])

    def bfs(self, start, end):
        path = list()
        path.append(start)

        if start == end:
            return True

        visited = set()
        queue = deque()

        visited.add(start)
        queue.append(start)

        while len(queue) != 0:
            start = queue.popleft()

            if start in self.graph:
                for node in self.graph[start]:
                    if node not in visited:
                        path.append(node)
                        if node == end:
                            self.visualize(path)
                            return
                        visited.add(node)
                        queue.append(node)
            elif start in path:
                path.remove(start)

        self.visualize([])

    def visualize(self, path):
        print(path)
        # Set up graph
        Gr = nx.DiGraph()
        # edges = [(i+1, i+2) for i in range(10)] + [(i+2, i+1) for i in range(10)]
        # edges = [(0, 2), (2, 1), (1, 3), (5, 3), (3, 4), (1, 0)]
        Gr.add_edges_from(self.edges)

        # Get position using spring layout
        pos = nx.spring_layout(Gr)

        # Get shortest path
        # path = nx.shortest_path(Gr,source=0,target=4)
        path_edges = list(zip(path, path[1:]))

        # Draw nodes and edges not included in path
        nx.draw_networkx_nodes(Gr, pos, nodelist=set(Gr.nodes) - set(path))
        nx.draw_networkx_edges(
            Gr,
            pos,
            edgelist=set(Gr.edges) - set(path_edges),
            connectionstyle="arc3, rad = 0.3",
        )

        # Draw nodes and edges included in path
        nx.draw_networkx_nodes(Gr, pos, nodelist=path, node_color="r")
        nx.draw_networkx_edges(
            Gr,
            pos,
            edgelist=path_edges,
            edge_color="r",
            connectionstyle="arc3, rad = 0.3",
        )

        # Draw labels
        nx.draw_networkx_labels(Gr, pos)

        plt.show()


# Driver code
G = Graph()
G.addEdge(0, 2)
G.addEdge(2, 1)
G.addEdge(1, 3)
G.addEdge(5, 3)
G.addEdge(3, 4)
G.addEdge(1, 0)
G.dfs(2, 4)

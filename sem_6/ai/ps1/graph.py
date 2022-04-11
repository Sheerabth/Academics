class Graph:
    def __init__(self):
        self.adj_list = dict()
        self.edges = list()

    def addEdge(self, start, end):
        if start not in self.adj_list:
            self.adj_list[start] = list()

        self.adj_list[start].append(end)

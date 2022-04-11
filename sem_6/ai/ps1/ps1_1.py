from queue import Queue


class Graph:
    def __init__(self):
        self.adj_list = dict()
        self.edges = list()

    def addEdge(self, start, end):
        if start not in self.adj_list:
            self.adj_list[start] = list()

        self.adj_list[start].append(end)

        if end not in self.adj_list:
            self.adj_list[end] = list()

        self.adj_list[end].append(start)

    def dfs(self, start, target, path=list(), visited=set()):
        path.append(start)
        visited.add(start)
        if start == target:
            return path
        for neighbour in self.adj_list[start]:
            if neighbour not in visited:
                result = self.dfs(neighbour, target, path, visited)
                if result is not None:
                    return result
        path.pop()
        return None

    def bfs(self, start, target):
        visited = set()
        queue = Queue()

        queue.put(start)
        visited.add(start)

        parent = dict()
        parent[start] = None

        path_found = False
        while not queue.empty():
            current = queue.get()
            if current == target:
                path_found = True
                break

            for next_node in self.adj_list[current]:
                if next_node not in visited:
                    queue.put(next_node)
                    parent[next_node] = current
                    visited.add(next_node)

        path = list()
        if path_found:
            path.append(target)
            while parent[target] is not None:
                path.append(parent[target])
                target = parent[target]
            path.reverse()
        return path

    def dls(self, start, target, depth_limit, depth=0, path=list(), visited=set()):
        if depth > depth_limit:
            return None

        path.append(start)
        visited.add(start)
        if start == target:
            return path
        for neighbour in self.adj_list[start]:
            if neighbour not in visited:
                result = self.dls(
                    neighbour, target, depth_limit, depth + 1, path, visited
                )
                if result is not None:
                    return result
        path.pop()
        return None

    def ids(self, start, target, depth_limit):

        for i in range(depth_limit):
            path = self.dls(start, target, i)
            if path:
                return path

        return None


if __name__ == "__main__":
    g = Graph()
    g.addEdge(0, 1)
    g.addEdge(0, 2)
    g.addEdge(1, 3)
    g.addEdge(2, 3)
    g.addEdge(3, 4)
    dfs_path = g.dfs(0, 3)
    bfs_path = g.bfs(0, 3)
    print(dfs_path, bfs_path)

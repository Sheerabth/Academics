import networkx as nx
import matplotlib.pyplot as plt
from collections import deque

class GraphVisualization:

	def __init__(self):
		self.visual = []
		
	def addEdge(self, a, b):
		temp = [a, b]
		self.visual.append(temp)
		
	def visualize(self):
		G = nx.Graph()
		G.add_edges_from(self.visual)
		nx.draw_networkx(G)
		plt.show()

class Graph:

	def __init__(self):
		self.graph = dict();

	def addEdge(self, start, end):
		if start not in self.graph:
			self.graph[start] = list()

		self.graph[start].append(end)

	def dfs(self, start, end):
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
						if node == end:
							return True
						visited.add(node)
						stack.append(node)

		return False
		
	def bfs(self, start, end):
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
						if node == end:
							return True
						visited.add(node)
						queue.append(node)

		return False
		
# Driver code
G = Graph()
G.addEdge(0, 2)
G.addEdge(2, 1)
G.addEdge(1, 3)
G.addEdge(5, 3)
G.addEdge(3, 4)
G.addEdge(1, 0)
print(G.bfs(0, ))

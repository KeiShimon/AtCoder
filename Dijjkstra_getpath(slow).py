from collections import defaultdict
import heapq

'''
This version of Dijkstra search is slow due to the limitation of python-list.
Use this if and only if path is needed.
'''

class Dijkstra():
    def __init__(self, N):
        self.n_nodes = N
        self.edges = [[float('inf') for i in range(N)] for i in range(N)]

    def add_edge(self, a, b, cost, directed=False):
        self.edges[a][b] = cost
        if not directed:
            self.edges[b][a] = cost

    def delete_edge(self, a, b):
        self.edges[a][b] = float('inf')
        self.edges[b][a] = float('inf')

    def Dijkstra_search(self, start):
        '''
        Returns min distances to every node from start node(input).
        '''

        distances = [float('inf') for i in range(self.n_nodes)]
        distances[start] = 0

            # initialize a priority queue with heapq
        q = []
        heapq.heappush(q, (0, start))

        # store flags for each node to mark if the node has been visited
        if_visited = defaultdict(bool)

        while q:
            # search from a new node whose cost is known to be minimum among items in queue 
            cost_current, node_current = heapq.heappop(q)
            
            # skip if the node has already been visited
            if if_visited[node_current]:
                continue
            
            else:
                if_visited[node_current] = True

                # visit adjacent nodes
                for node_visiting, cost_visiting in self.edges[node_current]:

                    if if_visited[node_visiting]: # check if already visited
                        continue
                    
                    cost_cumulative = cost_current + cost_visiting

                    if cost_cumulative < distances[node_visiting]: # check if current path is worthy updating
                        distances[node_visiting] = cost_cumulative
                        heapq.heappush(q, (cost_cumulative, node_visiting))

        return distances

    def Dijkstra_get_path(self, start, goal):

        '''
        Returns a tuple of (list of path, int/float of the distance)
        '''
        
        # path to the node from start-node
        prev = [start] * self.n_nodes

        # distance to the node from start-node
        distances = [float("inf")] * self.n_nodes
        distances[start] = 0

        visited = [False] * self.n_nodes
        
        while True:

            # find a unvisited node which has minimum cost
            node = -1
            for i in range(self.n_nodes):
                if not visited[i]:
                    if node == -1 or distances[i] < distances[node]:
                        node = i
            
            # all nodes are visited
            if node == -1:
                break
            
            else:
                visited[node] = True

                for i in range(self.n_nodes):
                    if not visited[i]:
                        if distances[i] > distances[node] + self.edges[node][i]:
                            distances[i] = distances[node] + self.edges[node][i]
                            prev[i] = node

        path = [goal]
        while prev[goal] != start:
            path.append(prev[goal])
            prev[goal] = prev[prev[goal]]
        path.append(start)

        return reversed(path), distances[goal]




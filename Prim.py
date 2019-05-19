from collections import defaultdict
import heapq

'''
Prim's algorithm:
    This is a DP (greedy) algorithm that finds a minimum spanning tree(MST) for a weighted undirected graph.
    O(|E|.logE)

MST:
    MST is a subset of the edges that forms a tree that includes every vertex,
    where the total weight of all the edges in the tree is minimized.
'''

class Prim():
    def __init__(self, n_vertices):
        self.edges = defaultdict(list)
        self.Prim_edges = defaultdict(list)
        self.n_vertices = n_vertices

    def add_edge(self, a, b, cost, directed=False):
        '''
        Pay caytion when setting directed = True. (Prim usually assumes undirected graph.)
        '''

        self.edges[a].append((cost,b))
        self.edges[b].append((cost,a))

    def construct_MST_Prim(self, start=0):
        '''
        Input:
            start: starting vertex to initiate MST construction.
            Raise ValueError if starting vertex is isolated.
        '''

        # start-vertex is already part of Prim_subtree
        if start in self.Prim_edges.keys():
            return True

        # start-vertex is isolated
        elif not self.edges[start]:
            self.Prim_edges[start].append((-1, self.n_vertices))
            return True

        # construct MST!
        else: # initialize
            q = []
            done = set()

            for cost, vertex in self.edges[start]:
                heapq.heappush(q, (cost, start, vertex))
            
            cost, _, b = heapq.heappop(q) # _ is equivalent to start in initializing block
            self.Prim_edges[start].append((cost, b))
            self.Prim_edges[b].append((cost, start))
            done.add(start)
            for cost, vertex in self.edges[b]:
                heapq.heappush(q, (cost, b, vertex))

        while q:
            cost, a, b = heapq.heappop(q)

            if b not in done:
                self.Prim_edges[a].append((cost, b))
                self.Prim_edges[b].append((cost, a))
                done.add(b)
                for cost, vertex in self.edges[b]:
                    heapq.heappush(q, (cost, b, vertex))

            if len(done) == self.n_vertices: # works as desired if and only if there is no isolated vertex
                break

        return True
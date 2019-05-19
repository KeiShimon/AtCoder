from collections import defaultdict
import heapq

'''
Kruskal's algorithm:
    This is a DP (greedy) algorithm that finds a minimum spanning tree(MST) for a weighted undirected graph.
    O(|E|.logE)

If edges are given by reverse-sorted order, re-implement heapq part and the algorithm becomes faster.

MST:
    MST is a subset of the edges that forms a tree that includes every vertex,
    where the total weight of all the edges in the tree is minimized.
'''


class Kruskal():
    def __init__(self, n_vertices):
        self.n_vertices = n_vertices
        self.parent = [-1] * n_vertices
        self.edges = []
        self.Kruskal_edges = defaultdict(list)

    def root(self, a):
        '''
        Returns indea of the root of the union to which a belongs to.
        '''

        if self.parent[a] < 0:
            return a

        else:
            self.parent[a] = self.root(self.parent[a])
            return self.parent[a]
    
    def unite(self, a, b):
        '''
        Unite two vertices a and b.\n
        Input:
            a and b: indices of vertices to unite.\n
        Returns:
            True if a and b are in different unions.
            False if a and b are in the same union.
            
        '''

        a_root, b_root = self.root(a), self.root(b)

        if a_root == b_root:
            return False

        else:
            self.parent[b_root] = a_root # merge union_b into union_a
            return True

    def add_edge(self, a, b, cost):
        heapq.heappush(self.edges, (cost, a, b))

    def construct_MST_Kruskal(self):
        
        if self.Kruskal_edges:
            done = set(self.Kruskal_edges.keys())
        else:
            done = set()
        
        while self.edges:
            cost, a, b = heapq.heappop(self.edges)

            if self.unite(a, b):
                done.add(a)
                done.add(b)

                self.Kruskal_edges[a].append((cost,b))
                self.Kruskal_edges[b].append((cost,a))

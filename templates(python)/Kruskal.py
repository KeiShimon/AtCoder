from collections import defaultdict

'''
Kruskal's algorithm:
    This is a DP (greedy) algorithm that finds a minimum spanning tree(MST) for a weighted undirected graph.
    O(|E|.logE)

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
        Returns index of the root of the union to which a belongs to.
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
        self.edges.append((cost, a, b))

    def construct_MST_Kruskal(self):
        '''
        Returns True if MST is constructed and it contains all the vertices.
        Returns False if MST is complete but some isolated vertices exists.

        When False is returned, current MST is a subtree without isolated verticies.
        '''

        # some MST already exists
        if self.Kruskal_edges:
            done = set(self.Kruskal_edges.keys())

            # MST construction is already complete and there is no isolated vertex
            if len(done) == self.n_vertices:
                return True

            # MST construction is already complete but there is some isolated vertex
            elif not self.edges:
                return False

        else:
            done = set()

        self.edges.sort(key=lambda x: x[0], reverse=True)

        while self.edges:
            cost, a, b = self.edges.pop()

            if self.unite(a, b):
                done.add(a)
                done.add(b)

                self.Kruskal_edges[a].append((cost,b))
                self.Kruskal_edges[b].append((cost,a))

            if len(done) == self.n_vertices:
                return True

        return False
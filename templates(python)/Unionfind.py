class UnionFind():
    def __init__(self, n):
        # negative if parent
        # if parent, absolute value represents the number of vertices in the union
        # if child, value represents the parent vertex to it
        self.parent = [-1] * n

    def root(self, x):
        '''
        Returns index of the root of the union to which x belongs to.
        '''

        if self.parent[x] < 0:
            return x

        else:
            # recursively trace parents until it gets to a root
            # while recursive call, update every vertex so that they are directly connected to their common parent to reduce tree size.
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]

    def size(self, x):
        '''
        Returns the size of the union to which input index belongs.
        '''

        return -1 * self.parent[self.root(x)]

    def unite(self, x, y):
        '''
        Unite two vertices x and y.\n
        Input:
            x and y: indices of vertices to unite.\n
        Returns:
            0 if x and y are in the same union.
            Otherwise, returns the number of new paths created by merging two unions, which is
                (size_of_union_x_before_unite) * (size_of_union_y_bofore_unite)
        '''

        x, y = self.root(x), self.root(y)

        if x == y:
            return 0

        else:
            size_x = - self.size(x)
            size_y = - self.size(y)

            # attach y into x
            # but before that make sure y is shorter so that always shorter tree is atached to longer tree for efficiency
            if size_x > size_y:
                x, y = y, x

            self.parent[x] += self.parent[y]
            self.parent[y] = x

            return size_x * size_y
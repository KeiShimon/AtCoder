import sys

class UnionFind():
    def __init__(self, n):
        self.parent = [-1] * n
        
    def root(self, x):
        '''
        Returns the index of the root of the union to which x belongs.
        '''

        if self.parent[x] < 0:
            return x

        else:
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
            x and y: indices of vertices to unite.
        '''

        x, y = self.root(x), self.root(y)

        if x == y:
            return False

        else:
            size_x = - self.size(x)
            size_y = - self.size(y)

            if size_x > size_y:
                x, y = y, x

            self.parent[x] += self.parent[y]
            self.parent[y] = x

            return True


input = sys.stdin.readline
N, M = map(int, input().split())
uf = UnionFind(N)
for _ in range(M):
    x,y,z = map(int, input().split())
    x -= 1
    y -= 1
    uf.unite(x,y)

roots = set()
for i in range(N):
    roots.add(uf.root(i))

print(len(roots))
N, M = map(int, input().split())
AB = []

for _ in range(M):
    a, b = map(int, input().split())
    AB.append((a-1, b-1))

class UnionFind():
    def __init__(self, n):
        # negative if parent
        # if parent, absolute value represents the number of nodes in the union
        # if child, value represents the parent node to it
        self.parent = [-1 for _ in range(n)]
        
    def root(self, x):
        if self.parent[x] < 0:
            return x

        else:
            # recursively trace a parent node until it gets to a root while updating every node so that they are directly connected to their common parent
            self.parent[x] = self.root(self.parent[x])
            return self.parent[x]

    def size(self, x):
        return -1 * self.parent[self.root(x)]
    
    def union(self, x, y):
        x = self.root(x)
        y = self.root(y)

        if x == y:
            return 0

        else:
            size_x = - self.size(x) 
            size_y = - self.size(y)

            # make sure y is shorter so that always shorter tree(y) is atached to longer tree(x) 
            if size_x > size_y:
                x, y = y, x 

            self.parent[x] += self.parent[y]
            self.parent[y] = x

            return size_x * size_y

n_solo = N * (N - 1) // 2 
ans = [n_solo]
uf = UnionFind(N)

for a, b in reversed(AB):

    united = uf.union(uf.root(a), uf.root(b))
    n_solo -= united

    ans.append(n_solo)
    
for a in reversed(ans[:-1]):
    print(a)

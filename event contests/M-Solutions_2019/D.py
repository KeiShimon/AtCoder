import sys
import heapq
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def NULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def NULTIPLE_INT_NAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def NULTIPLE_STRING(): return INPUT().split()

class Node():
    def __init__(self, a,b):
        self.id = a
        self.marked = False
        self.adjacent = [b]
        self.n_adjacent = 1

    def add_edge(self, n):
        self.adjacent.append(n)
        self.n_adjacent += 1

N = SINGLE_INT()
leaf = set(range(N))
node = {}
node_marking = [0] * N

for _ in range(N-1):
    a, b = NULTIPLE_INT_NAP()
    a -= 1
    b -= 1

    if a in node:
        node[a].add_edge(b)
        try:
            leaf.remove(a)
        except:
            pass
    else:
        node[a] = Node(a,b)

    if b in node:
        node[b].add_edge(a)
        try:
            leaf.remove()
        except:
            pass
    else:
        node[b] = Node(b,a)

figures = NULTIPLE_INT_LIST()
figures.sort(reverse=True)
max_of_min = sum(figures[1:])

q = [(1, n) for n in leaf]

while figures:
    _, id = heapq.heappop(q)
    #print('visiting', id)

    visiting = node[id]

    if visiting.marked:
        continue

    visiting.marked = True
    node_marking[visiting.id] = figures.pop()

    for n in visiting.adjacent:
        adj = node[n]
        adj.n_adjacent -= 1
        if not adj.marked:
            heapq.heappush(q, (adj.n_adjacent, n))
            #print('added (', adj.n_adjacent, n, ')')

print(max_of_min)
print(' '.join(map(str, node_marking))) 
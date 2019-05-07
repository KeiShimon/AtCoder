from collections import deque
import sys

input = sys.stdin.readline

N = int(input())

# an adjacent list
edges = [[] for _ in range(N)]

# add edges
for _ in range(N - 1):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    edges[a].append(b)
    edges[b].append(a)


# find radius of tree by running bfs twice
def bfs(i):
    """
    Input\n
        i: a node to start BFS given as an index. \n
    Returns\n
        (v,d): a tuple of furthest vertex v and their distance.
    """

    distance = [-1 for _ in range(N)] # list of distance from node i
    distance[i] = 0

    q = deque([i])
    while q:
        v = q.popleft()
        d = distance[v]

        # iterate over unvisited nodes
        for nv in filter(lambda x: distance[x] == -1, edges[v]):
            distance[nv] = d + 1
            q.append(nv)
    
    return v, d


x, _ = bfs(0)
_, d = bfs(x)

print('Second' if d % 3 == 1 else 'First')

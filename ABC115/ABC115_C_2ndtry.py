import heapq
import queue

N, K = map(int, input().split())

trees = []
heapq.heapify(trees)

for _ in range(N):
    heapq.heappush(trees, int(input()))

ans = 1 + 10**9

q = queue.Queue(maxsize=K-1)

for _ in range(K-1):
    q.put(heapq.heappop(trees))

for _ in range(N-K+1):
    curmin = q.get()
    nextmin = heapq.heappop(trees)

    ans = min(ans, nextmin-curmin)

    q.put(nextmin)

print(ans)


'''
Solution2
'''

import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

N, K = MULTIPLE_INT_MAP()
trees = [int(input()) for _ in range(N)]
trees.sort()

# faster
print(min([trees[i+K-1]-trees[i] for i in range(N-K+1)]))

# slower
ans = float('inf')
for i in range(0, N-K+1):
    ans = min(ans, trees[i+K-1] - trees[i])
    if ans == 0:
        break
print(ans)
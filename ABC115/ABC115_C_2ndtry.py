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

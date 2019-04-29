import bisect

N, K = map(int, input().split())

trees = []

for _ in range(N):
    item = int(input())
    trees.insert(bisect.bisect_left(trees, item), item)    

curmin = 1 + 10**9

for i in range(N-K+1):
    curmin = min(curmin, trees[i+K-1] - trees[i])

print(curmin)
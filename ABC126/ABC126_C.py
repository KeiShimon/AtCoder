import sys

input = sys.stdin.readline

N, K = map(int, input().split())

X = [0] * N

for i in range(1,N+1):
    j = i
    tmp = 1

    while(j<K):
        j *= 2
        tmp /= 2

    X[i-1] = tmp

ans1 = sum(X) / N
print(ans1)


from math import log2, ceil
from collections import defaultdict


d = defaultdict(int)

for die in range(1,N+1):

    if die < K:
        d[ceil( log2( K/die ) )] += 1

    else:
        d[0] += 1

cumulative = 0

for power in d:
    current = d[power]
    for _ in range(power):
        current /= 2

    cumulative += current

# print('{:.10f}'.format(cumulative / N))

my_ans = cumulative / N

print(my_ans)

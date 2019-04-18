import numpy as np

N,M,C = map(int, input().split())
Bs = np.array(list(map(int, input().split())))
ans = 0

for _ in range(N):
    As = np.array(list(map(int, input().split())))
    if np.sum(As * Bs) + C > 0:
        ans += 1

print(ans)
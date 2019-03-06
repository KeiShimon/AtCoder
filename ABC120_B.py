#%%
from fractions import gcd

#%%
a, b, k = map(int, input().split())
g = gcd(a,b)
l = []

for i in range(1,g+1):
    if a % i == 0 and b % i == 0:
        l.append(i)

print(l[-k])
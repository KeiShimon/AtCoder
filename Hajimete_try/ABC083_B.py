n,a,b = map(int, input().split())

cursum = 0

for x in range(1, n+1):
    y = sum(map(int, str(x)))
    if a <= y and y <= b:
        cursum += x

print(cursum)

#%%
n, a, b = map(int, input().split())
ans = 0
for i in range(n+1):
    if a <= sum(list(map(int, list(str(i))))) <= b:
        ans += i
print(ans)

#%%
x = 1234
y = sum(map(int, str(x)))
print(y)

#%%

n,a,b = 20,2,5
cursum = 0

for x in range(1, n+1):
        y = sum(map(int, str(x)))
        if a <= y and y <= b:
        cursum += x

print(cursum)

#%%
import numpy as np

n = int(input())
a = np.array(list(map(int, [input() for i in range(n)])))

print(len(np.unique(a)))


#%%
n = int(input())
print(len(set(map(int, [input() for i in range(n)]))))
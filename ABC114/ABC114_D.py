N = int(input())


prime = [2,3,5]

def isPrime(n):
    if n == 1:
        return False

    if n == 2 or n==3 or n==5:
        return True

    for div in prime:
        if n % div == 0:
            return False
    
    prime.append(n)
    return True

for x in range(1, N+1):
    isPrime(x)


#%%
def factoring(n):

    for div in prime:
        if div > n:
            break

        while n % div == 0:
            part[div] += 1
            n /= div

#%%
part = {x:0 for x in prime}
for x in range(1, N+1):
    factoring(x)

use = {3:0, 5:0, 15:0, 25:0, 75:0}
for x in part:
    if part[x] >= 2:
        use[3] += 1
    if part[x] >= 4:
        use[5] += 1
    if part[x] >= 14:
        use[15] += 1
    if part[x] >= 24:
        use[25] += 1
    if part[x] >= 74:
        use[75] += 1

ans = 0
# 75 = 75 * 1
if 75 in use:
    ans += use[75]
# 75 = 25 * 3
if 25 in use:
    ans += use[25] * (use[3] - 1)
# 75 = 15 * 5
if 15 in use:
    ans += use[15] * (use[5] - 1)
# 75 = 5 * 5 * 3
if 5 in use:
    ans += use[5] * (use[5] - 1) / 2 * (use[3] - 2)

print(int(ans))



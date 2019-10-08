from math import sqrt
from collections import defaultdict
N = int(input())
divisors = []
ans = 0

for i in range(1, int(sqrt(N))+1):
    if N % i == 0:

        if i ** 2 != N:
            divisors.append(i)
            divisors.append(int(N/i))

        else:
            divisors.append(i)

for div in divisors[1:]:
    d = int(N//(div-1))
    
    if d == N - d * (div-1):
        ans += div-1
        
print(ans)
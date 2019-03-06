from functools import reduce
from fractions import gcd

n = int(input())

a = list(map(int, input().split()))

g = reduce(gcd, a)

print(g)
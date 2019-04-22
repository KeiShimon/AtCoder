abc = list(map(int,input().split()))

abc.sort()

abc.pop()

print(int(abc[0] * abc[1] / 2))
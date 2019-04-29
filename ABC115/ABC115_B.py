N = int(input())

current = 0
curmax = -1

for _ in range(N):
    item = int(input())

    current += item
    curmax = max(curmax, item)


current -= int(curmax / 2)

print(current)
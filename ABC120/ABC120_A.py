cost, wallet , target = map(int, input().split())

t = wallet //cost

if t > target:
    print(target)
else:
    print(t)
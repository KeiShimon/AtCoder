def f(x): return int(x/2) if x % 2 == 0 else (3*x + 1)

s = int(input())
a = set([s])
i = 1

while True:
    s = f(s)
    i += 1

    if s not in a:
        a.add(s)

    else:
        print(i)
        break


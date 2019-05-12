R, G, B, N = map(int, input().split())

#%%
colors = [R, G, B]
colors.sort()

ma = colors[2]
mid = colors[1]
mi = colors[0]

ans = 0
target = N
a, b = 0, 0

while target >= 0:

    while target >= 0:
        if target % mi == 0:
            ans += 1
        b += 1
        target -= mid

    a += 1
    b = 0
    target = N - a * ma

print(ans)
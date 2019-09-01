N = int(input())
H = list(map(int, input().split()))

ans = 0
curmax = -1

for h in H:

    if curmax <= h:
        ans += 1
        curmax = h

print(ans)
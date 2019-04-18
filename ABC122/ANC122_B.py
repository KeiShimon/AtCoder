S = input()

allowed = set(list('ATCG'))

ans = 0
curstreak = 0
flag = False

for char in S:
    if char in allowed:

        if flag:
            curstreak += 1
        else:
            flag = True
            curstreak = 1
        
        ans = max(ans, curstreak)

    else:
        if flag:
            flag = False
            curstreak = 0

print(ans)

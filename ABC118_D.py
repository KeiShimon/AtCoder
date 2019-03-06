cost_digit = { 2: [1], 3:[7], 4:[4], 5: [2,3,5], 6: [6,9], 7: [8]}
digit_cost = [2,5,5,4,5,6,3,7,6]

n, m = map(int, input().split())

materials = list(map(int,input().split()))

cost = set([digit_cost[x-1] for x in materials])

minpart = set()
for c in cost:
    if c == 2 or c == 3:
        minpart.add(c)
    elif c == 4:
        if 2 not in minpart:
            minpart.add(4)
    elif c == 5:
        if 2 not in minpart or 3 not in minpart:
            minpart.add(5)
    elif c == 6:
        if 2 not in minpart and 3 not in minpart:
            minpart.add(6)
    else: # c== 7
        if 2 not in minpart or 3 not in minpart:
            if 3 not in minpart or 4 not in minpart:
                if 2 not in minpart or 5 not in minpart:
                    minpart.add(7)


usedigit = []
result = {}

for part in minpart:
    result[part] = {part : 1}
    usedigit.append(max(set(cost_digit[part]) & set(materials)))

usedigit.sort(reverse=True)


for target in range(max(minpart)+1, n+1):

    for part in minpart:

        curtarget = target - part
        if curtarget in result:
            d = result[curtarget].copy()
            if part in d:
                d[part] += 1
            else:
                d[part] = 1

            result[target] = d
            break

ans = ''
res = result[n]

for d in usedigit:
    if digit_cost[d-1] in res:
        ans += ''.join([str(d) for _ in range(res[digit_cost[d-1]])])
    
print(ans)


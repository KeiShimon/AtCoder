#%%

n = int(input())

now = 0
x, y = 0, 0
flag = True

for _ in range(n):
    t, x_target, y_target = map(int, input().split())

    distance = abs(x_target - x) + abs(y_target - y)
    duration = t - now

    if distance > duration:
        flag = False
        break
    
    elif distance % 2 != duration % 2:
        flag = False

if flag:
    print('Yes')
else:
    print('No')
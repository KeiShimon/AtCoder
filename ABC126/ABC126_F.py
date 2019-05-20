import sys

input = sys.stdin.readline
M, K = map(int, input().split())

ma = 2 ** M

if M == 0:
    if K > 0:
        print(-1)
    else:
        print('0 0')

elif M == 1:
    if K != 0:
        print(-1)
    else:
        print('0 0 1 1')

elif K >= ma:
    print(-1)

else:
    arr = [x for x in range(ma) if x != K]

    for i in arr:
        print(i, end=' ')
    print(K, end=' ')

    for i in arr[::-1]:
        print(i, end=' ')
    print(K)

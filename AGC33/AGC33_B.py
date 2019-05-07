import sys

input = sys.stdin.readline

H, W, N = map(int, input().split())
y, x = map(int, input().split())
x -= 1
y -= 1
remover = input()
stayer = input()

top, btm, left, right = 0, H-1, 0, W-1

def solve(top, btm, left, right):
    for s, r in zip(stayer, remover):

        if s == 'U':
            btm = min(btm+1, H-1)
        elif s == 'D':
            top = max(top-1, 0)
        elif s == 'R':
            left = max(left-1, 0)
        else: # 'L'
            right = min(right+1, W-1)

        if r == 'U':
            top += 1
        elif r == 'D':
            btm -= 1
        elif r == 'R':
            right -= 1
        else: # 'L'
            left += 1

        if right < left:
            return 'NO'
        
        if btm < top:
            return 'NO'


    if top <= y <= btm and left <= x <= right:
        return 'YES'
    else:
        return 'NO'

print(solve(top, btm, left, right))

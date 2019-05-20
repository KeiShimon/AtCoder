N, K = map(int, input().split())

S = input()

for i, c in enumerate(S,1):
    if i == K:
        print(c.lower(), end='')
    else:
        print(c,end='')

print('')
N = int(input())
S = input()
K = int(input())

target = S[K-1]

ans = ''

for c in S:
    if c != target:
        ans += '*'
    else:
        ans += target

print(ans)
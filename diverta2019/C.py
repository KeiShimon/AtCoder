import sys

input = sys.stdin.readline

N = int(input())
A, B, AB = 'A', 'B', 'AB'
endA, startB, startB_endA = 0, 0, 0
ans = 0

for _ in range(N):
    S = input().rstrip()

    if S[0] == B:
        startB += 1

        if S[-1] == A:
            startB -= 1
            startB_endA += 1

    elif S[-1] == A:
        endA += 1
    

    for i in range(1,len(S)):
        if S[i-1] + S[i] == AB:
            ans += 1


if startB_endA == 0:
    ans += min(endA, startB)

elif endA == 0 and startB == 0:
    ans += max(0, startB_endA - 1)

else:
    ans += startB_endA + min(endA, startB)

print(ans)
import sys
INPUT = sys.stdin.readline
S = list(input())
S.reverse()
L = len(S)
A, B, C = 'A', 'B', 'C'

followingAs = 0
searchABC = 0
ans = 0

while S:

    last = S.pop()

    if last == A:
        if searchABC == 0:
            searchABC = 1
            followingAs += 1
            continue
        
        elif searchABC == 1:
            followingAs += 1
            continue
        
        else: #searchABC == 2:
            searchABC = 1
            followingAs = 1
            continue
    
    elif last == B:
        if searchABC == 0:
            continue

        elif searchABC == 1:
            searchABC += 1
            continue

        else: # searchABC == 2:
            searchABC = 0
            followingAs = 0
            continue

    else: # last == C

        if searchABC == 0:
            continue

        elif searchABC == 1:
            followingAs = 0
            searchABC = 0
            continue

        else:
            ans += followingAs
            searchABC = 1
            continue

print(ans)
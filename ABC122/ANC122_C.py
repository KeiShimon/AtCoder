N, Q = map(int, input().split())
S = input()
target = 'AC'
shiftID = len(target) - 1

found_id = []

for i in range(N-shiftID):
    if S[i:i+len(target)] == target:
        found_id.append(i)

found_count = [0 for _ in range(N+1)]

for i in range(shiftID+1, N+1):
    found_count[i] = found_count[i-1] + (1 if S[i-shiftID-1:i]=='AC' else 0)



for _ in range(Q):
    l, r = map(int, input().split())
    print(found_count[r] - found_count[l])

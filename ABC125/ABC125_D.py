N = int(input())
A = list(map(int,input().split()))

curmin = 1 + 10**9
negatives = 0
cursum = 0

for item in A:

    curmin = min(curmin, abs(item))

    if item < 0:
        negatives += 1

    cursum += abs(item)

if negatives % 2 == 1:
    cursum -= 2 * curmin

print(cursum)
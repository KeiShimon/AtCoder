from collections import deque
import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

N = SINGLE_INT()
arr = MULTIPLE_INT_LIST()
arr.sort()

if N == 2:
    print(arr[1] - arr[0])
    print(arr[1], arr[0])

else:
    left = 0
    right = N - 1

    positives = (N + 1) // 2

    print(sum(arr[-positives:]) - sum(arr[:-positives]))

    if N % 2 == 1:
        # init
        print(arr[0], arr[N-1])
        last = arr[0] - arr[N-1]
        right -= 1
        left += 1

        for i in range(1,N-1):
            if i % 2 == 1:
                print(arr[right], last)
                last = arr[right] - last
                right -= 1
            else:
                print(arr[left], last)
                last = arr[left] - last
                left += 1

    else:
        # init
        print(arr[N-1], arr[0])
        last = arr[N-1] - arr[0]
        right -= 1
        left += 1

        for i in range(1, N-1):
            if i % 2 == 1:
                print(arr[left], last)
                last = arr[left] - last
                left += 1
            else:
                print(arr[right], last)
                last = arr[right] - last
                right -= 1

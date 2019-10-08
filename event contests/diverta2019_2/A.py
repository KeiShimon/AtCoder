import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

N, K = MULTIPLE_INT_MAP()

if K == 1:
    print(0)
else:
    print(N-K)
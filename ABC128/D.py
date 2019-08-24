import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_FLOAT(): return float(INPUT())
def MULTIPLE_FLOAT_LIST(): return list(map(float, INPUT().split()))
def MULTIPLE_FLOAT_MAP(): return map(float, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

falsestart = set()

N, Q = MULTIPLE_INT_MAP()

for _ in range(N):

    s, t, x = MULTIPLE_INT_MAP()

    for i in range(s-x, t-x):
        falsestart.add(i)

ans = 0
for _ in range(Q):    
    start = SINGLE_INT()
    if start not in falsestart:
        ans += 1
print(ans)
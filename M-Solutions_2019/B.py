import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

S = SINGLE_STRING()
counter = 15

for c in S:
    if c == 'x':
        counter -= 1

if counter > 7:
    print('YES')
else:
    print('NO')
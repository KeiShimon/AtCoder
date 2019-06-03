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

A, B = MULTIPLE_INT_MAP()

print((A*3 + B) // 2)

import sys
import numpy as np

from itertools import combinations_with_replacement, permutations

INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_FLOAT(): return float(INPUT())
def MULTIPLE_FLOAT_LIST(): return list(map(float, INPUT().split()))
def MULTIPLE_FLOAT_MAP(): return map(float, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

n_switches, n_bulbs = MULTIPLE_INT_MAP()
bulbs = np.zeros((n_bulbs, n_switches))
targets = []

for i in range(n_bulbs):
    ipt = MULTIPLE_INT_LIST()

    for j in ipt[1:]:
        bulbs[i, j-1] = 1

targets = MULTIPLE_INT_LIST()

done = set()
ans = 0
for iter1 in combinations_with_replacement([0,1], n_switches):
    for iter2 in permutations(iter1):

        current = tuple(iter2)

        if current in done:
            continue

        done.add(current)
        arr = np.array(current)

        for i in range(n_bulbs):
            if targets[i] != np.sum(arr[np.where(bulbs[i])]) % 2:
                flag = False
                break
        
        if flag:
            ans += 1
        else:
            flag = True

print(ans)

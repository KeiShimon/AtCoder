import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

n = SINGLE_INT()
arr = MULTIPLE_INT_LIST()

sum_arr = sum(arr)
current_sum = 0
ans = float('inf')

for x in arr:
    current_sum += x
    
    diff = abs(sum_arr - 2 * current_sum)
    ans = min(ans, diff)
    if ans == 0:
        break
    
    
print(ans)
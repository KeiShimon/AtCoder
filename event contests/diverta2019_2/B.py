import sys
import itertools
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

def recursive_add(loc, dx, dy):
    nxt = (loc[0] + dx, loc[1] + dy)
    if nxt not in locs:
        return 0

    done_initializer.add(tuple(sorted([loc, nxt])))
    return 1 + recursive_add(nxt, dx, dy)

N = SINGLE_INT()
locs = set()

for _ in range(N):
    locs.add(tuple(MULTIPLE_INT_MAP()))

count = 0
done_initializer = set()

for first, second in itertools.combinations(locs, 2):
    if tuple(sorted([first, second])) not in done_initializer:
        current_count = 0
        dx, dy = second[0] - first[0], second[1] - first[1]
        current_count += recursive_add(first, dx, dy)
        current_count += recursive_add(first, -dx, -dy)
        current_count += 1
        count = max(count, current_count)

print( N - count + 1)
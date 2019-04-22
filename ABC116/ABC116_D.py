import heapq
from collections import defaultdict

N, K = map(int, input().split())

sushi = []
for _ in range(N):
    kind, value = map(int, input().split())
    sushi.append((value,kind))
sushi.sort()


choice = []
heapq.heapify(choice)

current_sum = 0
kinds = set()
count_nitems_bykind = defaultdict(int)

# pick K items with highest value
for _ in range(K):
    item = sushi.pop()
    count_nitems_bykind[item[1]] += 1
    kinds.add(item[1])
    current_sum += item[0]
    heapq.heappush(choice, item)

# initialize a dict to store max value that can be achieved by selecting x kinds of sushi
# key: x, value: max value
max_value = {len(kinds):current_sum}


def replace():
    '''
    Returns a next sushi that is new in kind and has maximum value
    '''

    while sushi:
        candidate = sushi.pop()
        if candidate[1] not in kinds:
            kinds.add(candidate[1])
            return candidate

    return None

while sushi and choice:
    # pick a sushi that has min value
    sushi_min = heapq.heappop(choice)

    # check if that sushi is a duplicate, then, if yes, replace with a new sushi whose kind is new and value is max among such
    if count_nitems_bykind[sushi_min[1]] > 1:

        # pick a candidate
        sushi_new = replace()
        if sushi_new is None:
            break

        #replace
        count_nitems_bykind[sushi_min[1]] -= 1
        heapq.heappush(choice, sushi_new)

        # add a new result to dict
        current_sum = current_sum - sushi_min[0] + sushi_new[0]
        max_value[len(kinds)] = current_sum

    if len(kinds) == K: # already iterated enough to find answer
        break

ans = -1

for key in max_value:
    ans = max(ans, max_value[key] + key**2)

print(ans)
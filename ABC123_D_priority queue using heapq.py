'''
Implement and make use of priority queue using heapq module.
Using priority queue(heapq) is fast because all of insertion, deletion, and popping is done by order O(log n).

heapq documentation: https://docs.python.org/ja/3/library/heapq.html
'''

import heapq
# heapq a.k.a priority queue

X, Y, Z, K = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
C = list(map(int, input().split()))

A.sort(reverse=True)
B.sort(reverse=True)
C.sort(reverse=True)


# Initialize heap.
# Values are given as negative integers, because python heapq is a min-heap and pops minimum value in it.
# The form of values are tuple of (-value, indices of A,B,C).
# Indices are used to push new candidates to the heap after pop.
candidates = [] # name of the heap
heapq.heappush(candidates, (-(A[0]+B[0]+C[0]), 0,0,0))

# Initialize a set to store indices of A, B, and C so that there won't be any duplicates.
used = {(0,0,0)}

for _ in range(K):

    s, i, j, k = heapq.heappop(candidates)
    print(-s)

    if i < X-1 and (i+1,j,k) not in used:
        heapq.heappush(candidates, (-(A[i+1]+B[j]+C[k]), i+1,j,k))
        used.add((i+1,j,k))

    if j < Y-1 and (i,j+1,k) not in used:
            heapq.heappush(candidates, (-(A[i]+B[j+1]+C[k]), i,j+1,k))
            used.add((i,j+1,k))

    if k < Z-1 and (i,j,k+1) not in used:
            heapq.heappush(candidates, (-(A[i]+B[j]+C[k+1]), i,j,k+1))
            used.add((i,j,k+1))

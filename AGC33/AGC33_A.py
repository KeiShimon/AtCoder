import sys
import numpy as np

#%% Smart Solution

input = sys.stdin.readline

H, W = map(int, input().split())

status = np.full((H, W), H*W, dtype=int)
for i in range(H):
    for j, c in enumerate(input()):
        if c == "#":
            status[i,j] = 0


for h in range(1, H):
    status[h, :] = np.minimum(status[h, :], status[h-1, :] + 1)
for h in range(0, H-1)[::-1]:
    status[h, :] = np.minimum(status[h, :], status[h+1, :] + 1)
for w in range(1, W):
    status[:, w] = np.minimum(status[:, w], status[:, w-1] + 1)
for w in range(0, W-1)[::-1]:
    status[:, w] = np.minimum(status[:, w], status[:, w+1] + 1)

print(np.max(status))

#%%
# Original
import sys
import numpy as np

todo = [[], []]

input = sys.stdin.readline
H, W = map(int, input().split())
field = np.zeros((H,W), dtype=int)

for i in range(H):
    for j, c in enumerate(input()):
        if c == '#':
            field[(i,j)] = 1
            todo[0].append((i,j))

def findAdjacent(loc):
    x, y = loc[0], loc[1]
    for dx, dy in [(-1,0), (1,0), (0,-1), (0,1)]:
        if -1 < x+dx < W and -1 < y+dy < H:
            yield (x+dx, y+dy)

def colorAdjacent(loc, nxt):
    for l in findAdjacent(loc):
        if field[l] == 0:
            todo[nxt].append(l)
            field[l] += 1

ans = 0
while todo[0] or todo[1]:
    cur = ans % 2
    while todo[cur]:
        colorAdjacent(todo[cur].pop(), (cur+1)%2)
    ans += 1

print(ans-1)

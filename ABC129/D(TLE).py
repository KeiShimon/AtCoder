import sys
INPUT = sys.stdin.readline

def SINGLE_INT(): return int(INPUT())
def MULTIPLE_INT_LIST(): return list(map(int, INPUT().split()))
def MULTIPLE_INT_MAP(): return map(int, INPUT().split())
def SINGLE_STRING(): return INPUT()
def MULTIPLE_STRING(): return INPUT().split()

Y, X = MULTIPLE_INT_MAP()
encode = {'#': 1, '.' : 0}

grid = [[encode[x] for x in input()] for _ in range(Y)]
row_lighting = [[0 for _ in range(X)] for _ in range(Y)]
col_lighting = [[0 for _ in range(X)] for _ in range(Y)]

for row in range(Y):
    col, start, streak = 0, 0, 0
    while col < X:
        if grid[row][col]: # obstacle
            if streak == 0:
                start = col = col + 1
                continue
            else:
                for i in range(start, col):
                    row_lighting[row][i] = streak
                start = col = col + 1
                streak = 0

        else:
            streak += 1

            if col == X - 1:
                for i in range(start, X):
                    row_lighting[row][i] = streak
                start = col = col + 1
                streak = 0

            else:
                col += 1

for col in range(X):
    row, start, streak = 0, 0, 0
    while row < Y:
        if grid[row][col]: # obstacle
            if streak == 0:
                start = row = row + 1
                continue
            else:
                for i in range(start, row):
                    col_lighting[i][col] = streak
                start = row = row + 1
                streak = 0

        else:
            streak += 1

            if row == Y - 1:
                for i in range(start, Y):
                    col_lighting[i][col] = streak
                start = row = row + 1
                streak = 0

            else:
                row += 1

ans = float('-inf')
current = 0
MAX = X + Y - 1

for row in range(Y):
    for col in range(X):
        current = row_lighting[row][col] + col_lighting[row][col] - 1
        ans = max(ans, current)
        if ans == MAX:
            break

print(ans)
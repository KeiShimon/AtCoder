import numpy as np

t = np.array([int(input()) for _ in range(5)])
t_wasted = (10 - t % 10) % 10
last = np.argmax(t_wasted)

ans = 0

for i in range(5):
    ans += t[i]

    if i != last:
        ans += t_wasted[i]

print(ans)
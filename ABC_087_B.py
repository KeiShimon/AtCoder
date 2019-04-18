#%%
import numpy as np

#%%
a = int(input())
b = int(input())
c = int(input())
x = int(input())

n = 0
for fiveHundred in range(a+1):
    for hundred in range(b+1):
        for fifty in range(c+1):
            if x == 500*fiveHundred + 100*hundred + 50*fifty:
                n +=1

print(n)
#%%
import numpy as np

#%%
n = int(input())

arr = np.array(list(map(int, input().split())))

maxid = np.argmax(arr)

if arr[maxid] < np.sum(arr) - arr[maxid]:
    print('Yes')
else:
    print('No')
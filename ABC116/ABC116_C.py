import numpy as np

N = int(input())
h = np.array(list(map(int, input().split())))

#%%
def splitter(arr):
    '''
    Split arrays into sections that contain only non-zero values.\n
    Returns a list of tuples which are (start, open-end) of sections
    '''

    L = len(arr)
    sections = []
    l,r = 0,0

    while r < L:
        if arr[r] == 0:
            if l == r:
                l += 1
                r += 1
            else:
                sections.append((l,r))
                l = r

        else:
            if r == L-1:
                r += 1
                sections.append((l,r))

            else:
                r += 1

    return sections

#%%
def watering(arr):
    '''
    arr: np.array, that can contain both zero and nonzero values
    '''

    L = len(arr)

    if L == 1:
        return arr[0]

    # split into sections that contains only nonzero
    sections = splitter(arr)

    # already only 0s
    if not sections:
        return 0

    # for each section, decrement elements by 1 then recursive call this function
    operations = 0
    for l,r in sections:
        operations +=  1 + watering(arr[l:r] - 1)

    return operations


ans = watering(h)

print(ans)
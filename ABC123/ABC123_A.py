locs = [int(input()) for _ in range(5)]
k = int(input())
flag = False

for i in range(5-1):
    for j in range(i+1,5):

        if locs[j] - locs[i] > k:
            print(':(')
            flag = True
            break
    
    if flag:
        break

if not flag:
    print('Yay!')
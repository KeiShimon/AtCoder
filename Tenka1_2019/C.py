N = int(input())
S = input()

# . : white
# # : black
# no '#.' sequence

# a list that represents no of stone of the color interested up to that indices
nwhite, nblack = [], []

cur_nwhite, cur_nblack = 0, 0
for i, c in enumerate(S):
    if c == '.':
        cur_nwhite += 1
    else:
        cur_nblack += 1

    nwhite.append(cur_nwhite)
    nblack.append(cur_nblack)

if cur_nwhite == 0 or cur_nblack == 0:
    print(0)

else:
    # indices of start of the sequence of black stones
    black = []
    i = 0
    flag = False

    while(i<N):
        if S[i] == '#':
            if not flag:
                black.append(i)
                flag = True
        
        else:
            flag = False
        
        i += 1

    print('white: ',nwhite)
    print('black: ', nblack)
    print('i-black: ',black)

    ans = 2 * (10 ** 5) + 1

    # set a index that starts sequence of black(#)
    for i in black:

        curans = 0

        # then turn over all black(#) left to it
        if i > 0:
            curans = nblack[i-1]

        # then turn over all white(.) right to it    
        if i+1 < N:
            curans += nwhite[i+1]

        ans = min(ans, curans)

    print(ans)

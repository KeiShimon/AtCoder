N = int(input())
S = input()
N = len(S)
MAX = 2 * (10 ** 5)

# . : white
# # : black
# no '#.' sequence

# a list that represents no of stones seen up to the index
nwhite, nblack = [], []

nwhite_current, nblack_current = 0, 0

for c in S:
    if c == '.':
        nwhite_current += 1
    else:
        nblack_current += 1

    nwhite.append(nwhite_current)
    nblack.append(nblack_current)

if nwhite_current == 0 or nblack_current == 0:
    print(0)

else:
    # indices of start of the sequence of black stones
    black = []
    flag = False

    for i, c in enumerate(S):
        if c == '#':
            if not flag:
                black.append(i)
                flag = True
        
        else:
            flag = False

    # print('white: ',nwhite)
    # print('black: ', nblack)
    # print('i-black: ',black)

    ans = MAX + 1

    # set a index that starts sequence of black(#)
    for i in black:

        curans = 0

        # then turn over all black(#) left to it
        if i > 0:
            curans = nblack[i-1]

        # then turn over all white(.) right to it    
        curans += (nwhite_current - nwhite[i])

        ans = min(ans, curans)

    print(ans)

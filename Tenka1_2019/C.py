N = int(input())
S = input()

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

ans = 0

if nwhite_current != 0 and nblack_current != 0:

    ans = N + 1

    # set a index that starts sequence of black(#)
    for i in range(N):

        ans_current = 0

        # flip all black(#) left to it
        if i > 0:
            ans_current = nblack[i-1]

        # flip all white(.) right to it    
        ans_current += (nwhite_current - nwhite[i])

        ans = min(ans, ans_current)

print(ans)

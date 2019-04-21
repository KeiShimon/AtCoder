N, K = map(int, input().split())
S = input()

S = S + 'E' # end
ans = -1
L, R = 0, 0

orders = 1 if S[0] == '0' else 0

# scale-up method: 尺取り法
while (R < N):

    if (orders <= K):

        if S[R] == '1' and S[R + 1] == '0': # order!!
            orders += 1

        ans = max(ans, R - L + 1)

        R += 1

    # Available order exhansted. Now we need to move the left-end. 

    elif (L == R):
        L += 1
        R += 1
    else:
        if (S[L] == '0' and S[L + 1] == '1'):
            orders -= 1
        L += 1

print(ans)

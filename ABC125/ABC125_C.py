from fractions import gcd

N = int(input())
A = list(map(int, input().split()))

if N == 2:
    ans = max(A)

else:
    memo = {(0,0):1, (N,N):1}

    for i in range(1,N+1):

        if i == 1:
            memo[(0,1)] = A[0]
            memo[(N-1,N)] = A[-1]

        else:

            # gcd first i
            memo[(0,i)] = gcd(memo[(0,i-1)], A[i-1])

            # gcd last i
            memo[(N-i,N)] = gcd(memo[(N-i+1,N)], A[-i])

    # initialize answer: no change
    ans = memo[(0,N)]

    for i in range(1,N+1): # remove ith element and find gcd with rest of figures

        if i == 1:
            curgcd = memo[(1,N)]
        elif i == N:
            curgcd = memo[(0,N-1)]
        else:
            curgcd = gcd(memo[(0,i-1)], memo[(i,N)])

        ans = max(ans, curgcd)

print(ans)

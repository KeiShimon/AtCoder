n,m = map(int, input().split())
arr = list(map(int, input().split()))

if n >= m:
    print(0)

else:
    arr.sort()

    diff = [arr[i+1] - arr[i] for i in range(m-1)]
    diff.sort()

    print(sum(diff[0:m-n]))
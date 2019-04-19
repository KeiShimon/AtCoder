n, m = map(int, input().split())
dic = {}

for i in range(m,1):
    dic[i] = 0


for _ in range(n):
    arr = list(map(int, input().split()))

    for item in arr[1:]:

        if item in dic:
            dic[item] += 1
        else:
            dic[item] = 1

ans = 0
for count in dic.values():
    if count == n:
        ans += 1

print(ans)
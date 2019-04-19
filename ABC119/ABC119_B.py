n = int(input())
ans = 0

for _ in range(n):

    amount, currency = input().split()

    amount = float(amount)

    if currency == 'JPY':
        ans += amount
    else:
        ans += 380000 * amount

print(ans)
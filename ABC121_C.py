num_shops, target_drinks = map(int, input().split())
sell = {}

for _ in range(num_shops):
    a,b = map(int, input().split())

    try:
        sell[a] += b
    except:
        sell[a] = b

ans, bought = 0, 0

for price in sorted(sell):

    selling = sell[price]

    if bought + selling < target_drinks:
        ans += price * selling    
        bought += selling
    else:
        ans += price * (target_drinks - bought)
        break

print(ans)

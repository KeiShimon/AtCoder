def d_xxor(N, K, A):
    bit_max = 40  # N,K <= 10**12 < 2**40 なので、入力は40bit以下で表せる
    ans = 0

    for b in range(bit_max, -1, -1):
        power = 1 << b
        # Aの各要素を2進表記したとき、b番目のビットに1は何個立つか？
        bit_count_1 = len([1 for a in A if a & power != 0])

        # 解説における、「X_k=0とするか1とするか判定する」部分
        tmp = bit_count_1
        if power <= K and bit_count_1 <= N - bit_count_1:
            # X_k=1とした。XとKとの差を補正する。
            tmp = N - bit_count_1
            K -= power
        contribution = power * tmp

        ans += contribution  # 「b番目のビットがfに貢献する値」
    return ans

N, K = [int(i) for i in input().split()]
A = [int(i) for i in input().split()]
print(d_xxor(N, K, A))
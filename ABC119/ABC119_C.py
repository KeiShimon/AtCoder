#%%
import itertools

#%%

N, A, B, C = map(int, input().split())
materials = [int(input()) for _ in range(N)]

iterobj = itertools.product(range(4),repeat=N)

ans = 10**8

for use in iterobj:

    if 1 in use and 2 in use and 3 in use:

        synth = [0,0,0,0]

        for m, u in  zip(materials, use):
            synth[u] += m

        mp = 10 * (use.count(1) + use.count(2) + use.count(3) - 3)

        mp += abs(A-synth[1]) + abs(B-synth[2]) + abs(C-synth[3])

        ans = min(ans, mp)

print(ans)

#%%
import bisect

#%%
a,b,q = map(int, input().split())
INF = 10**18
shrines = [-INF] + [int(input()) for _ in range(a)] + [INF]
temples = [-INF] + [int(input()) for _ in range(b)] + [INF]

for _ in range(q):

    start = int(input())

    # スタート位置より右にある神社のうち、もっともスタート位置に近いもの
    shrine_east = shrines[bisect.bisect_right(shrines, start)]
    # スタート位置より右にある寺のうち、もっともスタート位置に近いもの
    temple_east = temples[bisect.bisect_right(temples, start)]

    # スタート位置より左にある神社のうち、もっともスタート位置に近いもの
    shrine_west = shrines[bisect.bisect_right(shrines, start) - 1]
    # スタート位置より左にある寺のうち、もっともスタート位置に近いもの
    temple_west = temples[bisect.bisect_right(temples, start) - 1]

    ans = INF

    for shrine in [shrine_east, shrine_west]:
        for temple in [temple_east,temple_west]:
            cur = min(abs(shrine-start), abs(temple-start)) + abs(shrine-temple)
            ans = min(ans,cur)

    print(ans)


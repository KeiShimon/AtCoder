H, W = map(int,input().split())
h, w = map(int,input().split())

ans = H * W - H * w - h * W + h * w

print(ans)
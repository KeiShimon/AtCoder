S = input()
ans = 999

for i in range(len(S)-2):
    x = int(S[i:i+3])

    if abs(x-753) < ans:
        ans = abs(x-753)

print(ans)
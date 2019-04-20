S = [int(c) for c in input()]
pairs = (len(S)+1) // 2

zeroone = 0
onezero = 0

for _ in range(pairs):

    last = S.pop()

    if last == 1:
        zeroone += 1
    else:
        onezero += 1

    if S:
        last = S.pop()
        if last == 0:
            zeroone += 1
        else:
            onezero += 1

print(min(zeroone, onezero))


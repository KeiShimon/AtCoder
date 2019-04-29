N, X = map(int, input().split())

thickness = [1] # memo
for i in range(1,N+1):
    thickness.append(thickness[i-1]*2+3)

def B(n): return 2**(n+1) - 1 # returns number of buns in level n


def eat(neat,level):

    if level == 0:
        return 1 if neat > 0 else 0

    elif neat < 2:
        return 0

    t = thickness[level]
    center = t//2 + 1

    if neat == t:
        return B(level)

    elif neat < center:
        return eat(neat-1, level-1)

    else: # neat >= center
        return 1 + B(level-1) + eat(neat - center, level-1)

print(eat(X, N))


N = int(input())
MOD = 10**9 + 7

memo = [{} for _ in range(N+1)]

# 前3つのアルファベットをもとに、OKなアルファベットを生成する
def genLegalChars(last3):

    if len(last3) != 3:
        print('Error! variable "last3" is not a string of length 3. None is returned in this function.')
        return None

    if last3[1:] == 'AG':
        return ['A','T','G']
    elif last3[1:] == 'GA':
        return ['A','T','G']
    elif last3[1:] == 'AC':
        return ['A','T','C']
    elif last3[0] == 'A' and last3[2] =='G':
        return ['A','G','T']
    elif last3[0:2] == 'AG':
        return ['A','G','T']
    else:
        return ['A','T','G','C']


def DFS(length, last3):

    # その長さで、その直前3つの場合の、そのノードの値が分かっている場合はそれを返す
    if last3 in memo[length]:
        return memo[length][last3]

    # 末端の（長さが既に求められている長さに等しい）場合は1を返す
    if length == N:
        return 1

    curNodeVal = 0
    # 次のノードに来ても良いアルファベットを列挙する
    # それぞれのアルファベットからノードを分岐させ、再帰呼び出し
    for char in genLegalChars(last3):
        curNodeVal = (curNodeVal + DFS(length+1, last3[1:]+char)) % MOD

    # メモ化してからreturnする
    memo[length][last3] = curNodeVal

    return curNodeVal

print(DFS(0,'TTT'))
# using this function takes too long time!
def step():

    for i in range(4,-1,-1):
        if state[i] <= capacities[i]:
            state[i+1] += state[i]
            state[i] = 0
        
        else:
            state[i+1] += capacities[i]
            state[i] -= capacities[i]

N = int(input())
capacities = [int(input()) for _ in range(5)]

state = [N,0,0,0,0,0]

# t = 0
# while True:
#     t += 1
#     step()

#     if state[-1] == N:
#         break


t = (N-1) // min(capacities) + 1 + 4

print(t)


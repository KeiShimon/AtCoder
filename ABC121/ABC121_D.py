'''
Important Property:
    For all even integer n, n ^ (n+1) = 1
'''

A, B = map(int, input().split())

#%%
# a finction to find F(0,x)
def XOR_0_to_x(x):

    # for all even integer n, n ^ (n+1) = 1
    xor = ((x+1) // 2) % 2

    if x % 2 == 0:
        return xor ^ x

    else:
        return xor

#%%
# F(A,B) = F(0,A-1) ^ F(0,B)
ans = XOR_0_to_x(A-1) ^ XOR_0_to_x(B)

print(ans)

#%%
XOR_0_to_x(7)

#%%

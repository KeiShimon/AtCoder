n, y = map(int, input().split())

def helper(n,y):

    for ten in range(n,-1,-1):
        for five in range(n-ten, -1,-1):


            one = n-ten-five
            sum = 10000*ten + 5000*five + 1000*one

            if y == sum:
                return('{} {} {}'.format(ten,five,one))


    return('-1 -1 -1')

print(helper(n,y))

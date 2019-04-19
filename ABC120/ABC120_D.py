#%%
class Graph:
    def __init__(self,n):
        '''Generate graph. n is the number of islands in the world.'''
        self.numIslands = n
        self.union = {}
        self.nextUnionKey = 1
        self.isolatedPath = int(n * (n-1) / 2)

    def getUnionId(self,island):
        '''returns union ID of the input island if the island belongs to any union'''
        for key in self.union:
            if island in self.union[key]:
                return key
        return None

    def addBridge(self,f,t):
        '''
        returns the no of isolated paths in the graph after adding a bridge
        unite unions if f and t are in different unions
        add new union if neither f nor t are belongs to some union
        add f or t to the belonging union if and only if one of them belongs to a union
        finally manage self.isolatedPath and return it
        '''

        f_union = self.getUnionId(f)
        t_union = self.getUnionId(t)

        if f_union:
            if t_union:
                if f_union != t_union:
                    # merge union
                    self.isolatedPath -= len(self.union[f_union]) * len(self.union[t_union])
                    self.union[f_union] += self.union[t_union]
                    del self.union[t_union]

                # else:
                #     pass

            else:
                self.isolatedPath -= len(self.union[f_union])
                self.union[f_union].append(t)

        else:
            if t_union:
                self.isolatedPath -= len(self.union[t_union])
                self.union[t_union].append(f)

            else:
                self.isolatedPath -= 1
                self.union[self.nextUnionKey] = [t,f]
                self.nextUnionKey += 1

        return self.isolatedPath

    def __str__(self):
        return str(self.union)

#%%
n,m = map(int, input().split())
bridges = []
for _ in range(m):
    bridges.append(list(map(int, input().split())))
bridges.reverse()

world = Graph(n)
ans = [world.isolatedPath]

for i, bridge in enumerate(bridges):
    ans.append(world.addBridge(bridge[0], bridge[1]))
ans.pop()

for a in ans[::-1]:
    print(a)



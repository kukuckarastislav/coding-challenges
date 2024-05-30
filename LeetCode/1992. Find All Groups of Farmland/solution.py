class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n: int = len(land)
        m: int = len(land[0])
        farmlands: List[List[int]] = []

        for i in range(n):
            for j in range(m):
                if land[i][j] == 1:
                    
                    for k in range(i, n):
                        if land[k][j] == 0:
                            k -= 1
                            break
                    for l in range(j, m):
                        if land[k][l] == 0:
                            l -= 1
                            break

                    farmlands.append((i,j,k,l))

                    for x in range(i, k+1):
                        for y in range(j, l+1):
                            land[x][y] = 0
                    

        return farmlands
    





class Solution:
    def findFarmland(self, land: List[List[int]]) -> List[List[int]]:
        n: int = len(land)
        m: int = len(land[0])
        farmlands: List[List[int]] = []

        i = 0
        while i < n:
            j = 0
            while j < m:
                
                if land[i][j] == 1:
                    jump = self.farmlandVisited(farmlands, i,j)
                    if jump > 0:
                        j = jump
                        continue
                    
                    for k in range(i, n):
                        if land[k][j] == 0:
                            k -= 1
                            break
                    for l in range(j, m):
                        if land[k][l] == 0:
                            l -= 1
                            break
                    
                    self.addFarmland(farmlands, i,j,k,l)
                j += 1
            i += 1

        return farmlands
    

    def addFarmland(self, farmlands: List[List[int]], i: int, j: int, k: int, l: int):
        #x = 0
        #for x in range(len(farmlands)):
        #    i1, j1, i2, j2 = farmlands[x]
        #    if i2 > k:
        #        if j2 > l:
        #            break
        #farmlands.insert(x, (i,j,k,l))
        farmlands.append((i,j,k,l))
        farmlands.sort(key = lambda x: (x[2], x[3]))

    
    def farmlandVisited(self, farmlands: List[List[int]], i: int, j: int) -> bool:
        for x in range(len(farmlands)-1, -1, -1):
            i1, j1, i2, j2 = farmlands[x]
            if i1 <= i <= i2 and j1 <= j <= j2:
                return j2+1
            if i2 < i and j2 < j:
                break
        return 0
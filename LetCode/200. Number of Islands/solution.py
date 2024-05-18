
'''
Runtime
243
ms
Beats
53.68%
of users with Python3
Memory
18.78
MB
Beats
97.75%
of users with Python3
'''
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        n = len(grid)
        m = len(grid[0])
        islands = 0

        for i in range(n):
            for j in range(m):
                if grid[i][j] == '1':
                    self.sinkIsland(grid, i, j)
                    islands += 1
        
        return islands
    

    def sinkIsland(self, grid, i, j):

        if i < 0 or j < 0 or i >= len(grid) or j >= len(grid[0]):
            return
        
        if grid[i][j] == '0':
            return
        
        grid[i][j] = '0'

        dx = [-1, 0, 1, 0]
        dy = [0, -1, 0, 1]
        for d in range(4):
            self.sinkIsland(grid, i+dx[d], j+dy[d])

        
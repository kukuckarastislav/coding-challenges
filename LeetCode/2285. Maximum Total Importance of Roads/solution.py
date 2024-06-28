from typing import List
from collections import defaultdict


# Runtime 1176ms Beats 96.31%
# Memory 41.99MB Beats 63.11% 
class Solution:
    def maximumImportance(self, n: int, roads: List[List[int]]) -> int:
        cityRoads = [0] * n

        for c1, c2 in roads:
            cityRoads[c1] += 1
            cityRoads[c2] += 1

        cityRoads.sort(reverse=True)

        total = 0
        currImportance = n
        for numOfRoads in cityRoads:
            total += currImportance * numOfRoads
            currImportance -= 1

        return total



if __name__ == '__main__':
    n = 5
    roads = [[0,1],[1,2],[2,3],[0,2],[1,3],[2,4]]
    
    sol = Solution()
    ans = sol.maximumImportance(n, roads)


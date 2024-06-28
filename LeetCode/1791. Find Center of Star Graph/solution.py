from typing import List
from collections import defaultdict

# Runtime 642ms Beats 88.21%
# Memory 50.87MB Beats 99.81%
class Solution:
    def findCenter(self, edges: List[List[int]]) -> int:
        mp = defaultdict(int)

        for e1, e2 in edges:
            mp[e1] += 1
            if mp[e1] > 1:
                return e1
            
            mp[e2] += 1
            if mp[e2] > 1:
                return e2
        
        return -1
            

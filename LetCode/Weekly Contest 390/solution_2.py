import math

class Solution:
    def minOperations(self, k: int) -> int:
        arr = [1]
        minOp = 0
        
        if k == 1:
            return 0
        
        if k == 2:
            return 1
        
        if k == 3:
            return 2
        
       
        k1 = math.ceil(math.sqrt(k))
        minOp = k1-1
        s = k1
        while k > s:
            minOp += 1
            s += k1
        return minOp
        
        
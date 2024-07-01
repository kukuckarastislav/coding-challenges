from typing import List


# Runtime 41ms Beats 89.04%
# Memory 16.69MB Beats 67.76% 
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        count = 0
        for x in arr:
            if x % 2:
                count += 1
                if count == 3:
                    return True
            else:
                count = 0
        
        return False


# Runtime 48ms Beats 50.88%
# Memory 16.65 MB Beats 67.76% 
class Solution1:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        i, n = 0, len(arr)
        while i < n-2:
            if arr[i] & 1:
                if arr[i+1]&1:
                    if arr[i+2]&1:
                        return True
                    else:
                        i += 2
                else:
                    i += 1
            i += 1

        return False
    

# 44ms Beats 76.21%
# Memory 16.72MB Beats 23.25%
class Solution2:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        n = len(arr)
        for i in range(n-2):
            if arr[i] % 2 == 1 and arr[i+1] % 2 == 1 and arr[i+2] % 2 == 1:
                return True
        return False
                


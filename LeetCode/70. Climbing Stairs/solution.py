
# Runtime 37ms Beats 39.40%
# Memory 16.38MB Beats 92.97%
class Solution:
    memo = {}
    def climbStairs(self, n: int) -> int:
        if n <= 2:
            return n
        
        if n in self.memo:
            return self.memo[n]
        
        r = self.climbStairs(n-1) + self.climbStairs(n-2)

        self.memo[n] = r
        return r
    


# Runtime 28ms Beats 91.20%
# Memory 16.42MB Beats 61.27%
class Solution1:
    def climbStairs(self, n: int) -> int:
        prev = 1
        curr = 1
        for i in range(2, n+1):
            curr = prev + curr
            prev = curr - prev
        
        return curr

        

        
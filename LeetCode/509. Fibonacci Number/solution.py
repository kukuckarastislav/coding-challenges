# Runtime 34ms Beats 75.17%
# Memory 16.46MB Beats 59.25%
class Solution:
    memo = {}
    def fib(self, n: int) -> int:
        if n == 0:
            return 0
        if n <= 2:
            return 1
        
        if n in self.memo:
            return self.memo[n]
        
        r = self.fib(n-1) + self.fib(n-2)

        self.memo[n] = r
        return r

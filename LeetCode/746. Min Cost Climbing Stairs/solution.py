from typing import List


# Runtime 55ms Beats 57.24%
# Memory 16.49MB Beats 99.21%
# Time:  O(n)
# Space: O(1)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        prev1 = 0
        prev2 = 0

        for i in range(n-1, -1, -1):
            prev1, prev2 = cost[i] + min(prev1, prev2), prev1

        return min(prev1, prev2)



# Runtime 51ms Beats 79.68%
# Memory 16.56MB Beats 92.50%
# Dynamic Programming, Bottom Up
# Time:  O(n)
# Space: O(n)
class Solution1:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0] * (n+2)

        for i in range(n-1, -1, -1):
            dp[i] = cost[i] + min(dp[i+1], dp[i+2])

        return min(dp[0], dp[1])



# Runtime 56ms Beats 50.67%
# Memory 17.86MB Beats 16.82%
# Recursion, memo, top down
# Time:  O(n)
# Space: O(n)
class Solution2:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        memo = [-1] * n

        def solve(i):
            if i >= n:
                return 0
        
            if memo[i] != -1:
                return memo[i]
            
            memo[i] = cost[i] + min(solve(i+1), solve(i+2))
            return memo[i]

        return min(solve(0), solve(1))





if __name__ == '__main__':
    sol = Solution()
    ans = sol.minCostClimbingStairs([10,15,20])
    


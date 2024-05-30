'''
Runtime
60
ms
Beats
81.93%
of users with Python3
Memory
17.68
MB
Beats
71.46%
of users with Python3
'''
class Solution:
    def findRelativeRanks(self, score: List[int]) -> List[str]:
        n = len(score)
        ans = [None]*n

        mp = {score[i] : i for i in range(n)}

        score.sort(reverse=True)

        if n > 0:
            ans[mp[score[0]]] = 'Gold Medal'
        if n > 1:
            ans[mp[score[1]]] = 'Silver Medal'
        if n > 2:
            ans[mp[score[2]]] = 'Bronze Medal'

        for i in range(3, n):
            ans[mp[score[i]]] = str(i+1)

        return ans
    
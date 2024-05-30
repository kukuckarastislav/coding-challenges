class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        lens = len(s)
        if lens == 0: return True
        lent = len(t)
        if len(s) > lent: return False

        i = 0
        for j in range(lent):
            if t[j] == s[i]:
                i += 1
                if i == lens:
                    return True
        
        return False
            
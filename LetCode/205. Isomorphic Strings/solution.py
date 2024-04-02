class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        d1 = dict()
        d2 = dict()
        for i in range(len(s)):
            c1 = s[i]
            c2 = t[i]
            if c1 in d1:
                if d1[c1] != c2:
                    return False
            else:
                d1[c1] = c2
            if c2 in d2:
                if d2[c2] != c1:
                    return False
            else:
                d2[c2] = c1

        return True
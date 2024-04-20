class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")
        p = len(pattern)
        if len(words) != p:
            return False
        
        dc = dict()
        sw = set()
        for i in range(p):
            if pattern[i] in dc:
                if dc[pattern[i]] != words[i]:
                    return False
            elif words[i]  in sw:
                return False
            else:
                dc[pattern[i]] = words[i] 
                sw.add(words[i] )
        
        return True
    






class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.split(" ")

        if len(words) != len(pattern):
            return False
        
        dc = dict()
        dw = dict()
        for c, w in zip(pattern, words):

            if c in dc:
                if dc[c] != w:
                    return False
            else:
                dc[c] = w

            if w in dw:
                if dw[w] != c:
                    return False
            else:
                dw[w] = c
        
        return True
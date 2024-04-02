class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = strs[0]
        for i in range(201):
            for word in strs:
                if i < len(word) and i < len(prefix):
                    if word[i] != prefix[i]:
                        if i == 0: 
                            return ""
                        return prefix[:i]
                else:
                    return prefix[:i]
                
        return prefix
    



class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        prefix = ""
        sortedStrs = sorted(strs)
        first = sortedStrs[0]
        last = sortedStrs[-1]
        for i in range(min(len(first), len(last))):
            if first[i] != last[i]:
                return prefix
            prefix += first[i]
                
        return prefix
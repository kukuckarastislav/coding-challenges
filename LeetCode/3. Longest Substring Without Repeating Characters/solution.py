class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        char_set = set()
        max_subs_len = 0
        i = 0
        for j in range(n):
            if s[j] not in char_set:
                char_set.add(s[j])
                if j-i+1 > max_subs_len:
                    max_subs_len = j-i+1
            else:
                while s[j] in char_set:
                    char_set.remove(s[i])
                    i += 1
                char_set.add(s[j])

        return max_subs_len
    
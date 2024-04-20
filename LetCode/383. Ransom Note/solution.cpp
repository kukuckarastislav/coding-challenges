class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> map(26, 0);

        for(char c:magazine)
            map[c-97]++;

        for(char c:ransomNote)
            if(map[c-97]-- == 0)
                return false;

        return true;
    }
};
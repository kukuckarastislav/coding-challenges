class Solution {
public:
    int strStr(string haystack, string needle) {
        int j = 0;
        for(int i = 0; i < haystack.size(); i++){
            if(haystack[i] == needle[j]){
                if(j == needle.size()-1){
                    return i - j;
                }
                j++;
            }else{
                i -= j;
                j = 0;
            }
        }

        return -1;
    }
};
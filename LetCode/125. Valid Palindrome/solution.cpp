class Solution {
public:
    bool isPalindrome(string s) { // 8ms 8.6mb
        int n = s.length();
        if(n <= 1)
            return true;

        int i = 0;
        int j = n - 1;
        
        while(i < j){

            if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
            if(s[j] >= 'A' && s[j] <= 'Z') s[j] += 32;

            if(s[i] < '0' || (s[i] > '9' && s[i] < 'a') || s[i] > 'z'){
                i++;
                continue;
            }

            if(s[j] < '0' || (s[j] > '9' && s[j] < 'a') || s[j] > 'z'){
                j--;
                continue;
            }

            

            if(s[i] != s[j]) 
                return false;

            i++;
            j--;
        }

        return true;
    }
};
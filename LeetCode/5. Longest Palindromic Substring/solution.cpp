#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;



/*
Runtime 9ms Beats 88.35%
Memory 8.13MB Beats 83.78%
*/
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();

        int maxLength = 1;
        int start = 0;

        for(int i = 0; i < n; i++){
            int l = i;
            int r = i;

            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLength){
                    maxLength = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }

            l = i;
            r = i+1;
            while(l >= 0 && r < n && s[l] == s[r]){
                if(r-l+1 > maxLength){
                    maxLength = r-l+1;
                    start = l;
                }
                l--;
                r++;
            }
        }

        return s.substr(start, maxLength);
    }
};



/*
Runtime 380ms Beats 20.72%
Memory 289.82MB Beats 15.96%
*/
// Dynamic Programming
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();
        int maxLength = 1;
        int startIndex = 0;
        int endIndex = 0;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;

        for(int step = 2; step <= n; step++){
            for(int i = 0; i < n-step+1; i++){
                int j = i+step-1;

                if(s[i] == s[j] && step == 2)
                    dp[i][j] = 2;
                else if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1] + 2;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j]);

                if(j-i+1 == dp[i][j] && dp[i][j] > maxLength){
                    startIndex = i;
                    endIndex = j;
                    maxLength = dp[i][j];
                }
            }
        }

        return s.substr(startIndex, endIndex-startIndex+1);
    }
};





// TLE, bruteforce
class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int n = s.size();

        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                string subs = s.substr(i, j-i+1);
                if(isPalindrom(subs)){
                    if(subs.size() > res.size()){
                        res = subs;
                    }
                }
            }
        }

        return res;
    }

private:
    bool isPalindrom(string& s){
        int n = s.size();
        for(int i = 0, j = n-1; i < j; i++, j--)
            if(s[i] != s[j])
                return false;
        return true;
    }
};
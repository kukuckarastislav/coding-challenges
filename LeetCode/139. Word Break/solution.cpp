#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.00
MB
Beats
90.77%
of users with C++
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i >= 0; i--){
            for(string& w : wordDict){
                int wl = w.length();
                if( i+wl <= n && dp[i+wl] && s.substr(i, wl) == w ){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};




/*
Runtime
6
ms
Beats
68.51%
of users with C++
Memory
12.24
MB
Beats
64.86%
of users with C++
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i >= 0; i--){
            for(int j = i; j < n; j++){
                if(dp[j+1] && wordSet.count(s.substr(i, j-i+1))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};






/*
Runtime
14
ms
Beats
43.22%
of users with C++
Memory
16.46
MB
Beats
37.30%
of users with C++
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());
        memo = vector<int>(n, 0);

        return tryToBreakStr(s, 0);
    }

private:
    unordered_set<string> wordSet;
    vector<int> memo; // Without memo - TLE

    bool tryToBreakStr(string& s, int i){
        int n = s.size();

        if(i >= n)
            return true;

        if(memo[i] == -1)
            return false;
        
        int j = i;
        while(j < n){
            if(wordSet.count(s.substr(i, j-i+1)))
                if(tryToBreakStr(s, j + 1))
                    return true;
        
            j++;
        }
        
        memo[i] = -1;
        return false;
    }
};






/*
    This solution is not correct because is greedy
    for example
    s = "aaaaaaa"
    wordDict = ["aaaa","aaa"]
    we would try to recreate as "aaa aaa a", and we do not have "a" in dict
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> set(wordDict.begin(), wordDict.end());

        int i = 0;
        int j = 0;
        while(j < n){
            if(set.count(s.substr(i, j-i+1)))
                i = j+1;

            j++;
        }

        if(i == n) return true;
        else return false;
    }
};
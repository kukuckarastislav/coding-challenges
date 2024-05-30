#include <vector>
#include <string>
using namespace std;


/*
Runtime
64
ms
Beats
95.56%
of users with C++
Memory
52.82
MB
Beats
78.24%
of users with C++
*/
// Dynamic Programming + Backtracking
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = 0; i < n; i++)
            dp[i][i] = true;

        for(int length = 2; length <= n; length++){
            for(int i = 0; i <= n - length; i++){
                int j = i + length - 1;
                if(s[i] == s[j] && (length == 2 || dp[i+1][j-1])){
                    dp[i][j] = true;
                }
            }
        }


        vector<vector<string>> ans;
        vector<string> path;

        backtrack(s,ans, path, 0, dp);

        return ans;
    }

private:
    void backtrack(string &s, vector<vector<string>>& ans, vector<string>& path, 
                   int start, vector<vector<bool>>& dp )
    {
        if(start == s.size()){
            ans.push_back(path);
            return;
        }

        int n = s.size();
        for(int end = start; end < n; end++){

            if(dp[start][end]){
                path.push_back(s.substr(start, end-start+1));
                backtrack(s, ans, path, end+1, dp);
                path.pop_back();
            }
        }

    }
};





/*
Runtime
67
ms
Beats
92.69%
of users with C++
Memory
52.65
MB
Beats
93.78%
of users with C++
*/
// Backtracking
class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;

        backtrack(s,ans, path, 0);

        return ans;
    }

private:
    void backtrack(string &s, vector<vector<string>>& ans, vector<string>& path, int start){
        if(start == s.size()){
            ans.push_back(path);
            return;
        }

        int n = s.size();
        for(int end = start + 1; end <= n; end++){

            if(isPalindrom(s, start, end-1)){
                path.push_back(s.substr(start, end-start));
                backtrack(s,ans, path, end);
                path.pop_back();
            }
        }

    }

    // s contains only lowercase English letters
    bool isPalindrom(string& s, int start, int end){
        int n = s.size();
        if(start > end or end >= n) 
            return false;

        while(start < end){
            if(s[start] != s[end])
                return false;
            
            start++;
            end--;
        }

        return true;
    }
};


int main(){

    string s = "aab";
    Solution sol;
    auto res = sol.partition(s);

    return 0;
}
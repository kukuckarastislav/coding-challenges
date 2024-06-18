#include <string>
#include <vector>
using namespace std;



/*
Runtime 0ms Beats 100.00%
Memory 7.78MB Beats 88.28%
*/
/*
    Time:  O(n*m)
    Space: O(m)
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if(n3 != n1 + n2)
            return false;

        if(n1 < n2)
            return isInterleave(s2, s1, s3);

        vector<bool> dp(n2+1, false);
        dp[0] = true;

        for(int j = 1; j <= n2; j++)
            dp[j] = dp[j-1] && s2[j-1] == s3[j-1];

        for(int i = 1; i <= n1; i++){
            dp[0] = dp[0] && (s1[i-1] == s3[i-1]);
            for(int j = 1; j <= n2; j++){
                dp[j] = (dp[j] && s1[i-1] == s3[i+j-1]) || (dp[j-1] && s2[j-1] == s3[i+j-1]);
            }
        }

        return dp[n2];
    }
};



/*
Runtime 3ms Beats 73.59%
Memory 8.03MB Beats 80.71%
*/
/*
    Time:  O(n*m)
    Space: O(n*m)
*/
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n3 = s3.size();

        if(n3 != n1 + n2)
            return false;

        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));
        dp[n1][n2] = true;

        for(int i = n1; i >= 0; i--){
            for(int j = n2; j >= 0; j--){
                if( (i < n1 && s1[i] == s3[i+j] && dp[i+1][j]) ||
                    (j < n2 && s2[j] == s3[i+j] && dp[i][j+1]) )
                {
                    dp[i][j] = true;
                }
            }
        }

        return dp[0][0];
    }
};
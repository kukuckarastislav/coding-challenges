#include <string>
#include <vector>
using namespace std;


/*
Runtime 3ms Beats 92.41%
Memory 9.44MB Beats 92.74%
*/
// Space: O(2*n) , n is word2.size
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(2, vector<int>(n2+1, 0));

        for(int j = n2-1; j >= 0; j--)
            dp[n1%2][j] = n2-j;
        
        for(int i = n1-1; i >= 0; i--){
            dp[i%2][n2] = n1-i;
            for(int j = n2-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    dp[i%2][j] = dp[(i+1)%2][j+1];
                }else{
                    dp[i%2][j] = 1 + min(min(dp[(i+1)%2][j], dp[i%2][j+1]), dp[(i+1)%2][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};




/*
Runtime 3ms Beats 92.41%
Memory 12.06MB Beats 34.69%
*/
// Space O(n*m) n,m is size of word1, word2
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size();
        int n2 = word2.size();

        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = n1-1; i >= 0; i--)
            dp[i][n2] = n1-i;

        for(int j = n2-1; j >= 0; j--)
            dp[n1][j] = n2-j;
        
        for(int i = n1-1; i >= 0; i--){
            for(int j = n2-1; j >= 0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = 1 + min(min(dp[i+1][j], dp[i][j+1]), dp[i+1][j+1]);
                }
            }
        }

        return dp[0][0];
    }
};


int main(){

    string word1 = "horse";
    string word2 = "ros";

    Solution sol;
    int ans = sol.minDistance(word1, word2);


    return 0;
}
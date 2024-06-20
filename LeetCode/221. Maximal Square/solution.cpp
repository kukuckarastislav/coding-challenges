#include <vector>
#include <algorithm>
using namespace std;



/*
Runtime 53ms Beats 92.54%
Memory 24.49MB Beats 55.92%
*/
// Dynamic Programming
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxSquare = 0;

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(dp[i+1][j+1], min(dp[i+1][j], dp[i][j+1]));
                    maxSquare = max(maxSquare, dp[i][j]);
                }
            }
        }

        return maxSquare * maxSquare;
    }
};



/*
Runtime 80ms Beats 19.54%
Memory 24.52MB Beats 27.94%
*/
// Recursion with memo
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        memo = vector<vector<int>>(n, vector<int>(m, -1));
        solve(matrix, 0, 0);

        return maxSquare * maxSquare;
    }

private:
    vector<vector<int>> memo;
    int maxSquare = 0;

    int solve(vector<vector<char>>& matrix, int i, int j){
        int n = matrix.size();
        int m = matrix[0].size();

        if(i >= n || j >= m) 
            return 0;

        if(memo[i][j] != -1)
            return memo[i][j];

        int right = solve(matrix, i, j+1);
        int bottom = solve(matrix, i+1, j);
        int diagonal = solve(matrix, i+1, j+1);

        int ans = 0;
        if(matrix[i][j] == '1'){
            ans = 1 + min(diagonal, min(right, bottom));
            maxSquare = max(maxSquare, ans);
            memo[i][j] = ans;
        }

        return ans;
    }
};


#include <vector>
using namespace std;


/*
Runtime 0ms Beats 100.00%
Memory 10.00MB Beats 89.88%
*/
/*
    Dynamic Programming, bottomup
    Time:  O(n*m)
    Space: O(m)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(obstacleGrid[0][0] == 1 || obstacleGrid[n-1][m-1] == 1)
            return 0;

        vector<long> dp(m, 0);
        dp[m-1] = 1;

        for(int j = m-2; j >= 0; j--){
            if(obstacleGrid[n-1][j] == 1)
                break;

            dp[j] = 1;
        }

        bool obstacleInLastCol = false;
        for(int i = n-2; i >= 0; i--){
            
            dp[m-1] = 1;
            if(obstacleGrid[i][m-1] == 1 || obstacleInLastCol){
                dp[m-1] = 0;
                obstacleInLastCol = true;  
            }

            for(int j = m-2; j >= 0; j--){
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else
                    dp[j] = dp[j] + dp[j+1];
            }
        }

        return dp[0];
    }
};




/*
Runtime 0ms Beats 100.00%
Memory 10.24MB Beats 35.04%
*/
/*
    Dynamic Programming, Recursion + Memoisation
    Time:  O(n*m)
    Space: O(n*m)
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
    
        memo = vector<vector<int>>(n, vector<int>(m, -1));

        return helper(obstacleGrid, 0, 0);
    }

private:
    vector<vector<int>> memo;

    int helper(vector<vector<int>>& obstacleGrid, int i, int j){
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if(i >= n || j >= m || obstacleGrid[i][j] == 1)
            return 0;

        if(i == n-1 && j == m-1)
            return 1;


        if(memo[i][j] != -1)
            return memo[i][j];

        int right = helper(obstacleGrid, i, j+1);
        int bottom = helper(obstacleGrid, i+1, j);

        memo[i][j] = right + bottom;
        
        return memo[i][j];
    }
};


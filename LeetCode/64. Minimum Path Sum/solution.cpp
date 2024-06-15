#include <vector>
#include <stdlib.h>
using namespace std;


/*
Runtime 5ms Beats 73.03%
Memory 12.08 MB Beats 95.63%
*/
/*
    Time:  O(n*m)
    Space: O(m)
*/
// less if statements 
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);
        dp[m-1] = grid[n-1][m-1];

        for(int j = m-2; j >= 0; j--)
            dp[j] = dp[j+1] + grid[n-1][j];

        for(int i = n-2; i >= 0; i--){
            dp[m-1] = dp[m-1] + grid[i][m-1];
            for(int j = m-2; j >= 0; j--){
                dp[j] = min(dp[j+1], dp[j]) + grid[i][j];
            }
        }

        return dp[0];
    }
};




/*
Runtime 0ms Beats 100.00%
Memory 12.25MB Beats 79.92%
*/
/*
    Time:  O(n*m)
    Space: O(m)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);
        dp[m-1] = grid[n-1][m-1];

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)
                    continue;

                int right  = (j == m-1) ? INT_MAX : dp[j+1];
                int bottom = (i == n-1) ? INT_MAX : dp[j];

                dp[j] = min(right, bottom) + grid[i][j];
            }
        }

        return dp[0];
    }
};





/*
Runtime 3ms Beats 94.98%
Memory 12.83MB Beats 11.69%
*/
/*
    Time:  O(n*m)
    Space: O(n*m)
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[n-1][m-1] = grid[n-1][m-1];

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                if(i == n-1 && j == m-1)
                    continue;

                int right  = (j == m-1) ? INT_MAX : dp[i][j+1];
                int bottom = (i == n-1) ? INT_MAX : dp[i+1][j];

                dp[i][j] = min(right, bottom) + grid[i][j];
            }
        }

        return dp[0][0];
    }
};
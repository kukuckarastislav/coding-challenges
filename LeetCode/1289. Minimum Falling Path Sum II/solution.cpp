#include <vector>
using namespace std;

/*
Runtime
18
ms
Beats
98.83%
of users with C++
Memory
16.82
MB
Beats
95.32%
of users with C++
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        vector<int> dp(n, 0);
        dp = grid[0];

        for(int i = 1; i < n; i++){

            int minIndex = getMinIndex(dp);
            int minEl = dp[minIndex];
            int minIndex2 = getMinIndexExceptOne(dp, minIndex);
            int minEl2 = dp[minIndex2];
            
            for(int j = 0; j < n; j++){
                if(j != minIndex){
                    dp[j] = minEl + grid[i][j];
                }else{
                    dp[j] = minEl2 + grid[i][j];
                }
            }
        }

        int k = getMinIndex(dp);
        return dp[k];
    }

    int getMinIndex(vector<int>& dp){
        int minEl = __INT_MAX__;
        int minIndex = 0;
        int n = dp.size();
        for(int i = 0; i < n; i++){
            if(dp[i] < minEl){
                minIndex = i;
                minEl = dp[i];
            }
        }
        return minIndex;
    }

    int getMinIndexExceptOne(vector<int>& dp, int ei){
        int minExc = __INT_MAX__;
        int minIndex = 0;
        int i = 0;
        while(i < ei){
            if(dp[i] < minExc){
                minIndex = i;
                minExc = dp[i];
            }
            i++;
        }
        int n = dp.size();
        i++;
        while(i < n){
            if(dp[i] < minExc){
                minIndex = i;
                minExc = dp[i];
            }
            i++;
        }
        return minIndex;
    }
};



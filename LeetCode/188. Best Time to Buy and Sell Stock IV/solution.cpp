#include <vector>
#include <stdlib.h>
#include <unordered_map>
#include <string>
#include <cstring>
using namespace std;


/*
Runtime 13ms Beats 43.63%
Memory 13.78MB Beats 71.89%
*/
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        memset(dp, -1, sizeof(dp));
        return solve(prices, 0, k, false);
    }

private:
    int dp[1001][101][2];

    int solve(vector<int>& prices, int idx, int k, bool isHoldingStock){
        int n = prices.size();

        if(idx == n || k == 0)
            return 0;

        if(dp[idx][k][isHoldingStock] != -1)
            return dp[idx][k][isHoldingStock];

        // we always can skip
        int newProfit = 0;
        newProfit = max(newProfit, solve(prices, idx+1, k, isHoldingStock));

        if(isHoldingStock){
            // we can only sell
            newProfit = max(newProfit, solve(prices, idx+1, k-1, false) + prices[idx]);
        }else{
            // we can only buy
            newProfit = max(newProfit, solve(prices, idx+1, k, true) - prices[idx]);
        }

        dp[idx][k][isHoldingStock] = newProfit;
        return newProfit;
    }
};




/*
Runtime 386ms Beats 5.44%
Memory 79.72MB Beats 6.47%
*/
// string concatenation is very slow for key in memo
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        return solve(prices, 0, k, false);
    }

private:
    unordered_map<string, int> mp;

    int solve(vector<int>& prices, int idx, int k, bool isHoldingStock){
        int n = prices.size();

        if(idx == n || k == 0)
            return 0;

        string key = to_string(idx) + '_' + to_string(k) + '_' + to_string(isHoldingStock);
        if(mp.count(key))
            return mp[key];

        // we always can skip
        int newProfit = 0;
        newProfit = max(newProfit, solve(prices, idx+1, k, isHoldingStock));

        if(isHoldingStock){
            // we can only sell
            newProfit = max(newProfit, solve(prices, idx+1, k-1, false) + prices[idx]);
        }else{
            // we can only buy
            newProfit = max(newProfit, solve(prices, idx+1, k, true) - prices[idx]);
        }

        mp[key] = newProfit;
        return newProfit;
    }
};







// TLE
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        solve(prices, 0, k, false, 0);
        return bestProfit;
    }

private:
    int bestProfit = 0;

    void solve(vector<int>& prices, int idx, int k, bool isHoldingStock, int profit){
        int n = prices.size();

        if(idx == n || k == 0){
            bestProfit = max(bestProfit, profit);
            return;
        }

        // we always can skip
        solve(prices, idx+1, k, isHoldingStock, profit);

        if(isHoldingStock){
            // we can only sell
            solve(prices, idx+1, k-1, false, profit+prices[idx]);
        }else{
            // we can only buy
            solve(prices, idx+1, k, true, profit-prices[idx]);
        }
    }
};
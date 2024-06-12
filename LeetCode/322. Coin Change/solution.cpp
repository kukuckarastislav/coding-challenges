#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



/*
Runtime
14
ms
Beats
96.43%
of users with C++
Memory
16.04
MB
Beats
70.05%
of users with C++
*/
// Dynamic Programming
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        
        for(int currAmount = 1; currAmount <= amount; currAmount++){
            for(int coin : coins){
                if(currAmount - coin >= 0){
                    dp[currAmount] = min(dp[currAmount], 1 + dp[currAmount - coin]);
                }
            }
        }

        if(dp[amount] == amount+1)
            return -1;

        return dp[amount];
    }
};



// optimal, TLE
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());

        dfs(coins, amount, 0, 0);

        if(optimalSteps == INT_MAX)
            return -1;

        return optimalSteps;
    }

private:
    int optimalSteps = INT_MAX;

    void dfs(vector<int>& coins, int amount, int currAmount, int steps){
        if(currAmount > amount || steps > optimalSteps) return;
        if(currAmount == amount) {
            optimalSteps = min(optimalSteps, steps);
            return;
        }

        for(int coin : coins){
            dfs(coins, amount, currAmount+coin, steps+1);
        }
    }

};




// not optimal, dfs
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());

        int ans = dfs(coins, amount, 0, 0);

        for(int x : path){
            cout << x << " ";
        }
        cout << endl;

        return ans;
    }

private:
    vector<int> path; 
    int dfs(vector<int>& coins, int amount, int currAmount, int steps){
        if(currAmount > amount) return -1;
        if(currAmount == amount) return steps;

        for(int coin : coins){
            path.push_back(coin); 
            int res = dfs(coins, amount, currAmount+coin, steps+1);
            if(res != -1)
                return res; 
            path.pop_back(); 
        }

        return -1;
    }

};



// Wrong Solution, greedy
/*
    The reason for this is non-uniformity of the coin elements, which lead us to wrong results for greedy. Thus, greedy fails for this case.

    Great observation. I also found out that the type of system where greedy would work is called "Canonical system". Currencies in India, USA are canonical form only.
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        int ans = 0;

        for(int i = n-1; i >= 0; i--){
            if(amount >= coins[i]){
                ans += amount / coins[i];
                amount = amount % coins[i];
            }

            if(amount == 0)
                return ans;
        }


        return -1;
    }
};
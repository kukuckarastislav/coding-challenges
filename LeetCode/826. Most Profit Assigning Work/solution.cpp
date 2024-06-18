#include <vector>
#include <algorithm>
using namespace std;


/*
Runtime 39ms Beats 93.30%
Memory 47.93MB Beats 17.53%
*/
// Dynamic Programming
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        int maxDiff = *max_element(difficulty.begin(), difficulty.end());
        vector<int> dp(maxDiff + 1, 0);
        
        for(int i = 0; i < n; i++)
            dp[difficulty[i]] = max(dp[difficulty[i]], profit[i]);

        for(int i = 1; i <= maxDiff; i++)
            dp[i] = max(dp[i], dp[i-1]);
        
        int totalProfit = 0;
        for(int w : worker){
            if(w > maxDiff)
                totalProfit += dp[maxDiff];
            else
                totalProfit += dp[w];
        }
        
        return totalProfit;
    }
};




/*
Runtime 43ms Beats 85.18%
Memory 41.04MB Beats 66.37%
*/
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();

        vector<pair<int, int>> diff_prof;
        for(int i = 0; i < n; i++)
            diff_prof.emplace_back(difficulty[i], profit[i]);

        sort(diff_prof.begin(), diff_prof.end());
        sort(worker.begin(), worker.end());

        int currMaxProf = 0;
        for(int i = 0; i < n; i++){
            if(diff_prof[i].second > currMaxProf)
                currMaxProf = diff_prof[i].second;
            
            diff_prof[i].second = currMaxProf;
        }

        int totalProfit = 0;
        int i = 0;

        for(int w : worker){
            while(i < n && diff_prof[i].first <= w) 
                i++;

            if(i == 0) 
                continue;

            totalProfit += diff_prof[i-1].second;
        }
        
        return totalProfit;
    }
};
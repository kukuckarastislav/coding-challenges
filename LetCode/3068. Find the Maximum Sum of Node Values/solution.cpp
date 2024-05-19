#include <vector>
#include <algorithm>
#include <bits/stdc++.h> // accumulate(nums.begin(), nums.end(), 0);
using namespace std;

/*
Runtime
178
ms
Beats
86.44%
of users with C++
Memory
125.73
MB
Beats
48.89%
of users with C++
*/
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {

        long long ans = accumulate(nums.begin(), nums.end(), 0ll);

        int n = nums.size();
        long long totalDiff = 0;
        long long diff;
        int positiveCount = 0;
        long long minAbsDiff = __INT_MAX__;

        for(int i = 0; i < n; i++){
            diff = (nums[i] ^ k) - nums[i];

            if(diff > 0){
                totalDiff += diff;
                positiveCount++;
            }

            minAbsDiff = min(minAbsDiff, abs(diff));
        }

        if(positiveCount % 2 == 1){
            totalDiff = totalDiff - minAbsDiff;
        }
     
        return ans + totalDiff;
    }
};









/*
Runtime
167
ms
Beats
93.11%
of users with C++
Memory
128.41
MB
Beats
41.11%
of users with C++
*/
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        
        long long ans = 0;
        vector<long long> delta(n, 0);
        for(int i = 0; i < n; i++){
            delta[i] = (nums[i] ^ k) - nums[i];
            ans += nums[i];
        }

        sort(delta.begin(), delta.end(), greater<long long>());

        for(int i = 0; i+1 < n; i+=2){
            long long action = delta[i] + delta[i+1];
            if(action <= 0)
                break;
            ans += action;
        }
        
        return ans;
    }
};
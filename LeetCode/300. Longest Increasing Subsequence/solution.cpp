#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;



/*
Runtime
9
ms
Beats
84.61%
Memory
12.82
MB
Beats
64.64%
*/
/*
    Time: O(N*logN)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> sub;

        for(int x : nums){
            if(sub.empty() || sub.back() < x){
                sub.push_back(x);
            }else{
                // lower_bound find the index of the first element >= x 
                auto it = lower_bound(sub.begin(), sub.end(), x); // binary search
                *it = x;
            }
        }
        
        return sub.size();
    }
};





/*
Runtime
60
ms
Beats
71.73%
Memory
12.82
MB
Beats
64.64%
*/
/*
    Time: O(n^2)
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        for(int i = n-1; i >= 0; i--){
            for(int j = i+1; j < n; j++){
                if(nums[i] < nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end()); 
    }
};
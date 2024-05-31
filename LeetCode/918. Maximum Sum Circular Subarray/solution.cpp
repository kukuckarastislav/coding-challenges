#include <cmath>
#include <vector>

using namespace std;


/*
Runtime
35
ms
Beats
94.56%
of users with C++
Memory
42.19
MB
Beats
90.31%
of users with C++
*/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxSum = nums[0];
        int currMaxSum = 0;

        int minSum = nums[0];
        int currMinSum = 0;

        int sum = 0;

        for(int x : nums){
            currMaxSum = max(currMaxSum + x, x);
            maxSum = max(maxSum, currMaxSum);

            currMinSum = min(currMinSum + x, x);
            minSum = min(minSum, currMinSum);

            sum += x;
        }

        if(maxSum > 0) return max(maxSum, sum - minSum);
        else return maxSum;
    }
};


// Kadane's Algorithm LC 53
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i = 0; i < n; i++){
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        
        return maxSum;
    }
};
*/


// 
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int maxSum = INT_MIN;
        int currSum = 0;

        int lastIdx = 0;

        for(int i = 0; i < n*2; i++){

            if(currSum <= 0){
                lastIdx = i;
                currSum = 0;
            }
            
            while(i > lastIdx && (i - lastIdx >= n || nums[lastIdx % n] <= 0)){
                currSum -= nums[lastIdx % n];
                lastIdx++;
            }

            currSum += nums[i % n];
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
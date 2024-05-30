#include <vector>
#include <stdlib.h>
using namespace std;



// Kadane's Algorithm
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





// TLE
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        int i = 0;
        int maxSum = INT_MIN;
        int currSum = 0;
        
        for(int i = 0; i < n; i++){
            currSum = 0;
            for(int j = i; j < n; j++){
                currSum += nums[j];
                maxSum = max(maxSum, currSum);
            }
        }
        
        return maxSum;
    }
};


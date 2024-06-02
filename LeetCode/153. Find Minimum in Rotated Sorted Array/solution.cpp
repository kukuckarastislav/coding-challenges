#include <vector>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
12.52
MB
Beats
59.00%
of users with C++
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int minEl = nums[0];

        if(n == 1 || nums[0] < nums[n-1]) 
            return minEl;

        int l = 0;
        int r = n - 1;
        int m;

        while(l <= r){
            m = l + (r - l) / 2;

            if(m > 0 && nums[m-1] > nums[m]){
                minEl = nums[m];
                break;
            }else if(nums[m] >= nums[0]){
                l = m + 1;
            }else if(nums[m] <= nums[n-1]){
                r = m - 1;
            }
        }

        return minEl;
    }
};
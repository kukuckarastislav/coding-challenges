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
11.97
MB
Beats
84.79%
of users with C++
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int left = 0;
        int right = n-1;

        while(left < right){
            int mid = left + (right - left) / 2;

            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid;
            }else{
                return mid;
            }
        }

        return right;
    }
};
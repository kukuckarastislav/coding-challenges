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
11.22
MB
Beats
50.97%
of users with C++
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return 0;

        int leftIndex = 0;
        int rightIndex = n-1;
        int mid;

        while(leftIndex <= rightIndex){
            mid = (leftIndex + rightIndex) / 2;

            if(isPeak(nums, mid)){
                return mid;
            }else if(!isLeftSmaller(nums, mid)){
                rightIndex = mid - 1;
            }else if(!isRightSmaller(nums, mid)){
                leftIndex = mid + 1;
            }
        }

        return rightIndex;
    }

private:
    bool isLeftSmaller(vector<int>& nums, int i){
        if(i == 0) return true;
        return nums[i-1] < nums[i];
    }

    bool isRightSmaller(vector<int>& nums, int i){
        if(i >= nums.size()-1) return true;
        return nums[i+1] < nums[i];
    }

    bool isPeak(vector<int>& nums, int i){
        return isLeftSmaller(nums, i) && isRightSmaller(nums, i);
    }
};
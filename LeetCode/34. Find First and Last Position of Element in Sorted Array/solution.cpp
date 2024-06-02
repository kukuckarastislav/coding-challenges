#include <vector>
using namespace std;

/*
Runtime
3
ms
Beats
88.95%
of users with C++
Memory
15.86
MB
Beats
98.53%
of users with C++
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        int l = 0;
        int r = n - 1;
        int m;
        bool targetIsPresent = false;

        // find target
        while(l <= r){
            m = l + (r - l) / 2;

            if(nums[m] < target){
                l = m + 1;
            }else if(nums[m] > target){
                r = m - 1;
            }else{
                targetIsPresent = true;
                break;
            }
        }

        if(!targetIsPresent)
            return {-1, -1};

        // find starting index of target sequence
        int ll = l;
        int rr = m;
        int leftIndex;
        while(ll <= rr){
            leftIndex = ll + (rr - ll) / 2;

            if(nums[leftIndex] == target){
                if(leftIndex <= 0 || nums[leftIndex - 1] < nums[leftIndex]) break;
                else rr = leftIndex - 1;
            }else if(nums[leftIndex] < target){
                ll = leftIndex + 1;
            }
        }

        // find ending index of target sequence
        ll = m;
        rr = r;
        int rightIndex = m;
        while(ll <= rr){
            rightIndex = ll + (rr - ll) / 2;

            if(nums[rightIndex] == target){
                if(rightIndex+1 >= n || nums[rightIndex] < nums[rightIndex + 1]) break;
                else ll = rightIndex + 1;    
            }else if(nums[rightIndex] > target){
                rr = rightIndex - 1;
            }
        }

        return {leftIndex, rightIndex};
    }
};
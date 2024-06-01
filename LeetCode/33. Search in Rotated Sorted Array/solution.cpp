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
13.47
MB
Beats
77.49%
of users with C++
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int k = findIndexOfRotation(nums);
        
        if(k == -1){
            return binarySearch(nums, 0, n-1, target);
        }else if(nums[0] <= target){
            return binarySearch(nums, 0, k, target);
        }else{
            return binarySearch(nums, k+1, n-1, target);
        }
    }

    int binarySearch(vector<int>& nums, int start, int end, int target){
        
        while(start <= end){
            int mid = (start + end) / 2;

            if(nums[mid] < target){
                start = mid + 1;
            }else if(nums[mid] > target){
                end = mid - 1;
            }else{
                return mid;
            }   
        }

        return -1;
    }

    int findIndexOfRotation(vector<int>& nums){
        int n = nums.size();

        if(n == 1 || nums[0] < nums[n-1])
            return -1;

        int left = 0;
        int right = n-1;
        int mid;

        while(left <= right){
            mid = (left + right) / 2;
            
            if(mid+1 < n && nums[mid] > nums[mid+1]){
                return mid;
            }else if(nums[mid] <= nums[n-1]){
                right = mid - 1;
            }else if(nums[mid] >= nums[0]){
                left = mid + 1;
            }
        }
        
        return right;
    }
};
#include <vector>
#include <algorithm>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.18
MB
Beats
53.24%
of users with C++
*/
// Binary Search
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());

        if (nums[n - 1] > n) return n;
        if(nums[0] < 1) return -1;

        int left = 0;
        int right = n-1;
        int mid;

        while(left <= right){
            mid = (left + right) / 2;

            if(nums[mid] > mid){
                left = mid + 1;
            }else if(nums[mid] < mid){
                right = mid - 1;
            }else{ 
                return -1;
            }
        }
       
        return (nums[mid] > mid) ? mid + 1 : mid;
    }
};




/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.16
MB
Beats
53.24%
of users with C++
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(nums[n-1] < 1) 
            return -1;

        int x = 0;
        for(int i = n-1; i >= 0; i--){
            if(nums[i] >= x){
                x++;
            }else if(x == n-(i+1) && x <= nums[i+1]){
                break;
            }else{
                return -1;
            }
        }

        return x;
    }
};
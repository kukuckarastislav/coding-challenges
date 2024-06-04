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
11.76
MB
Beats
81.03%
of users with C++
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for(int x : nums){
            ones ^= (x & ~twos);
            twos ^= (x & ~ones);
        }

        return ones;
    }
};





/*
Runtime
4
ms
Beats
79.18%
of users with C++
Memory
11.94
MB
Beats
36.24%
of users with C++
*/
// Idea: counting num of 1 for every bit position
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        int ans = 0;

        for(int i = 0; i < 32; i++){
            int sum = 0;
            for(int x : nums)
                sum += ((x >> i) & 1);

            sum = sum % 3;
            ans = ans | (sum << i);
        }
        
        return ans;
    }
};






/*
Runtime
6
ms
Beats
57.51%
of users with C++
Memory
12.06
MB
Beats
29.04%
of users with C++
*/
/*
    Time: O(n*long n)
    Space: O(1)
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];

        sort(nums.begin(), nums.end()); 

        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        for(int i = 1; i < n-1; i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return nums[i];
        }

        return -1;
    }
};
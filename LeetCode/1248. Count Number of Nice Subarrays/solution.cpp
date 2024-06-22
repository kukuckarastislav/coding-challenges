#include <vector>
using namespace std;

/*
Runtime 77ms Beats 97.22%
Memory 69.91MB Beats 65.04%
*/
/*
    Time:  O(n)
    Space: O(1)
*/
// Sliding window
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int odd = 0;
        int j = 0;
        int m = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] % 2)
                odd++;

            while(odd > k){
                if(nums[j] % 2)
                    odd--;
                j++;
                m = j;
            }

            while(j < i && nums[j] % 2 == 0) 
                j++;

            if(odd == k)
                ans += j-m+1;
        }

        return ans;
    }
};



// TLE
// Time: O(n*n)
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            int odd = 0;
            for(int j = i; j < n; j++){
                if(nums[j] % 2)
                    odd++;

                if(odd == k)
                    ans++;
                else if(odd > k)
                    break;
            }
        }

        return ans;
    }
};





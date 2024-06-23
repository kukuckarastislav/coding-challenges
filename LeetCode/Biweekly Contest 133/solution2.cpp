#include <vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int x : nums)
            sum += x;

        if(sum == n)
            return 0;

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] == 0 && i+2 < n){
                ans++;
                for(int j = i; j < i+3; j++){
                    if(nums[j])
                        nums[j] = 0;
                    else
                        nums[j] = 1;
                }
            }
        }

        for(int i = n-1; i > n-4; i--){
            if(nums[i] == 0)
                return -1;
        }

        return ans;
    }
};


int main(){

    vector<int> nums = {0,1,1,1};

    Solution sol;
    int x = sol.minOperations(nums);



    return 0;
}
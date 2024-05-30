#include <vector>
#include <iostream>
#include <bitset>
using namespace std;

/*Runtime
99
ms
Beats
87.96%
of users with C++
Memory
91.23
MB
Beats
85.86%
of users with C++*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            k ^= nums[i];
        }
        bitset<20> b(k);
        return b.count();
    }
};


int main(){

    Solution s;
    vector<int> nums({2,1,3,4});
    int ans = s.minOperations(nums, 1);

    return 0;
}


class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int x = 0;
        for(int i = 0; i < n; i++){
            x ^= nums[i];
        }
        x ^= k;
        int res = 0;
        while(x){
            res += x & 1;
            x >>= 1;
        }

        return res;
    }
};
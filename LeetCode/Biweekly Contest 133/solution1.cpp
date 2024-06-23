#include <vector>
using namespace std;

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        for(int x : nums){
            int r = x % 3;
            ans += min(1, r);
        }

        return ans;
    }
};
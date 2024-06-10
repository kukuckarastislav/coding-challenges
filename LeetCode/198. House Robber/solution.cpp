#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1 = 0;
        int rob2 = 0;

        // [rob1, rob2, x, x+1, x+2, ...]
        for(int x : nums){
            int rob3 = max(x + rob1, rob2);
            rob1 = rob2;
            rob2 = rob3;
        }   

        return rob2;
    }
};
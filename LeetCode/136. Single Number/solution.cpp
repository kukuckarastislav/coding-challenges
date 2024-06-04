#include <vector>
using namespace std;


/*
Runtime
3
ms
Beats
99.70%
of users with C++
Memory
19.28
MB
Beats
57.32%
of users with C++
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int singleOne = 0;
        for(int x : nums)
            singleOne ^= x;

        return singleOne;
    }
};
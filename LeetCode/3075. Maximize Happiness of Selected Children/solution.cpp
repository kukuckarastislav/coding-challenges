#include <vector>
#include <algorithm>
using namespace std;

/*
Runtime
147
ms
Beats
92.19%
of users with C++
Memory
106.89
MB
Beats
99.21%
of users with C++
*/
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;

        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i = 0; i < k; i++){
            int curr = happiness[i] - i;
            if(curr > 0)
                res += curr;
            else
                break;
        }

        return res;        
    }
};
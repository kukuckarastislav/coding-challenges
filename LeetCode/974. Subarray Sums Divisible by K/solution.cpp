#include <vector>
#include <unordered_map>
using namespace std;

/*
Runtime
37
ms
Beats
71.73%
of users with C++
Memory
35.10
MB
Beats
63.15%
of users with C++
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        int prefixSum = 0;
        unordered_map<int, int> prefixMap;
        prefixMap[0] = 1;

        for(int num : nums) {
            prefixSum += num;
            int mod = prefixSum % k;
        
            if(mod < 0)
                mod += k;
            
            if (prefixMap.count(mod)) {
                ans += prefixMap[mod];
                prefixMap[mod] += 1;
            } else {
                prefixMap[mod] = 1;
            }
        }
        
        return ans;
    }
};
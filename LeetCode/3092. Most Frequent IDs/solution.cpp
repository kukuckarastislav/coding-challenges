#include <vector>
#include <unordered_map>
using namespace std;

/*
Runtime
193
ms
Beats
96.08%
of users with C++
Memory
136.27
MB
Beats
98.73%
of users with C++
*/

class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, long long> mp;

        ans[0] = freq[0];
        mp[nums[0]] = freq[0];
        int maxNum = nums[0];

        for(int i = 1; i < n; i++){

            mp[nums[i]] += freq[i];

            if(maxNum == nums[i] && freq[i] < 0){
                // find new maximum?
                long long currMax = mp[maxNum];
                for(auto p : mp){
                    if(p.second > currMax){
                        currMax = p.second;
                        maxNum = p.first;
                    }
                }
            }else if(mp[nums[i]] > mp[maxNum]){
                maxNum = nums[i];
            }
            ans[i] = mp[maxNum];
        }

        return ans;
    }
};
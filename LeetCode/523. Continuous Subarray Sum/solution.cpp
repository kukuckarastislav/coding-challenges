#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;



/*
Runtime
163
ms
Beats
91.22%
of users with C++
Memory
134.58
MB
Beats
86.97%
of users with C++
*/
/*
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> modSeen;

        int prefixMod = 0;
        modSeen[0] = -1;

        for(int i = 0; i < n; i++){
            prefixMod = (prefixMod + nums[i]) % k;

            if(modSeen.count(prefixMod)){
                if(i - modSeen[prefixMod] > 1)
                    return true;
            }else{
                modSeen[prefixMod] = i;   
            }
        }

        return false;
    }
};





// TLE, Time: O(n^2)
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        for(int i = 0; i < n-1; i++){
            int currSum = 0;
            for(int j = i; j < n; j++){
                currSum += nums[j];
                if(j-i >= 1){
                    if(currSum % k == 0){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
#include <vector>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;


/*
Runtime
7
ms
Beats
97.73%
of users with C++
Memory
38.76
MB
Beats
34.71%
of users with C++
*/
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, vector<int>>mp;
        for (int el : nums){
            mp[el%k].push_back(el);
        }
        
        int ans = 1;

        for(auto& [mod_cal, v] : mp){

            sort(v.begin(), v.end());
            map<int, int> elCount;
            for (int el : v) 
                elCount[el]++;
            
            int prevEl = INT_MIN;

            int prevNotTaken = 1;
            int prevTaken = 0;
            int currNotTaken = 0;
            int currTaken = 0;

            for(auto& [el, freq] : elCount){

                int poss_subsets = pow(2, freq) - 1;
                
                currNotTaken = prevNotTaken + prevTaken;
                
                if(prevEl+k == el)
                    currTaken = prevNotTaken * poss_subsets;
                else
                    currTaken = (prevNotTaken + prevTaken) * poss_subsets;
                
                prevNotTaken = currNotTaken;
                prevTaken = currTaken;

                prevEl = el;
            }
            
            ans *= (currNotTaken + currTaken);                 
        }
        return ans - 1;
    }
};




/*
Runtime
795
ms
Beats
13.23%
of users with C++
Memory
38.72
MB
Beats
34.71%
of users with C++
*/
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 1;

        unordered_map<int, int> mp;
        int count = backtrack(nums, k, mp, 0) - 1;

        return count;
    }

    int backtrack(vector<int>& nums, int k, unordered_map<int, int>& mp, int i){
        if(i == nums.size())
            return 1;
        
        int res = backtrack(nums, k, mp, i + 1);
        if(!mp[nums[i] + k] and !mp[nums[i] - k]){
            mp[nums[i]] += 1;
            res += backtrack(nums, k, mp, i + 1);
            mp[nums[i]] -= 1;
        }

        return res;
    }
};




// TLE
class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 1;

        int allBits = (1 << n) - 1;
        int count = 0;

        for(int i = 1; i <= allBits; i++){
            vector<int> subs;
            int mask = i;
            for(int j = 0; j < n; j++){
                if(mask & 1)
                    subs.push_back(nums[j]);
                mask >>= 1;
            }

            if(isSubsBeautiful(subs, k))
                count++;
        }

        return count;
    }

    bool isSubsBeautiful(vector<int>& nums, int k){
        int n = nums.size();
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if(abs(nums[i]-nums[j]) == k){
                    return false;
                }
            }
        }

        return true;
    }
};
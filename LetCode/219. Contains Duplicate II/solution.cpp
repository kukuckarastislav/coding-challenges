#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>
using namespace std;


/*
Runtime
111
ms
Beats
84.80%
of users with C++
Memory
80.96
MB
Beats
33.99%
of users with C++
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            if(mp.count(nums[i])){
                if(abs(mp[nums[i]] - i) <= k){
                    return true;
                }
            }
            mp[nums[i]] = i;
        }

        return false;
    }
};  



/*
Runtime
94
ms
Beats
98.51%
of users with C++
Memory
76.62
MB
Beats
77.36%
of users with C++
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();

        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            return a.first < b.first;
        });

        for(int i = 0; i < n-1; i++){
            if(arr[i].first == arr[i+1].first){
                if(abs(arr[i].second - arr[i+1].second) <= k){
                    return true;
                }
            }
        }
    

        return false;
    }
};  
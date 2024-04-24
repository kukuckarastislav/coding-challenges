#include <vector>
#include <algorithm>
using namespace std;



/*
Runtime
3
ms
Beats
98.64%
of users with C++
Memory
13.74
MB
Beats
40.58%
of users with C++
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b){
                return a.first < b.first;
            }
        );

        int i = 0;
        int j = n-1;

        while(i < j){
            int s = arr[i].first + arr[j].first - target;
            if(s < 0){
                i++;
            }else if(s > 0){
                j--;
            }else{
                return {arr[i].second, arr[j].second};
            }
        }

        return {-1,-1}; // err
    }
};


/*
Runtime
11
ms
Beats
64.75%
of users with C++
Memory
14.02
MB
Beats
29.65%
of users with C++
*/
#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            int comp = target - nums[i];
            if(mp.count(comp)){
                return {mp[comp], i};
            }
            mp[nums[i]] = i;
            
        }

        return {-1,-1}; // err
    }
};
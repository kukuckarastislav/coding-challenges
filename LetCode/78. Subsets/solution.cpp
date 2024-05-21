#include <vector>
using namespace std;

#include <iostream>
#include <chrono>






/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.21
MB
Beats
81.15%
of users with C++
*/
// Recursive Backtracking
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> currSubs;

        backtrack(nums, 0, currSubs, subs);

        return subs;
    }

    void backtrack(vector<int>& nums, int start, 
                   vector<int>& currSubs, vector<vector<int>>& subs)
    {
        subs.push_back(currSubs);

        int n = nums.size();
        for(int i = start; i < n; i++){
            currSubs.push_back(nums[i]);
            backtrack(nums, i+1, currSubs, subs);
            currSubs.pop_back();
        }

    }
};



// Iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        
        vector<vector<int>> subs;
        subs.push_back({});

        for(int i = 0; i < n; i++){
            int m = subs.size();
            for(int j = 0; j < m; j++){
                vector<int> currSubs = subs[j];
                currSubs.push_back(nums[i]);
                subs.push_back(currSubs);
            }
        }
        
        return subs;
    }
};


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.26
MB
Beats
81.15%
of users with C++
*/
// BIT Manipulation
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int end = (1 << n) - 1;

        vector<vector<int>> subs;

        for(int i = 0; i <= end; i++){
            int mask = i;
            vector<int> currSubs;
            for(int j = 0; j < n; j++){
                if(mask & 1)
                    currSubs.push_back(nums[j]);
                mask >>= 1;
            }
            subs.push_back(currSubs);
        }

        return subs;
    }
};


/*  
    method:             numOfEl:    time: []

    Backtracing:        25          15.0818s, 16.576s
    BIT Manipulation:   25          168.475s
    Iterative:          25          91.8425s
*/


int main(){
    vector<int> nums;
    for(int i = 0; i <= 24; i++)
        nums.push_back(i);

    Solution sol;

    auto start = chrono::high_resolution_clock::now();
    auto res = sol.subsets(nums);
    auto end = chrono::high_resolution_clock::now();

    cout << (double)chrono::duration_cast<chrono::microseconds>(end-start).count()/1000000<< "s" <<endl;

    return 0;
}

#include <vector>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
9.03
MB
Beats
58.48%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums, 0);
        return allPermutation;
    }

private:
    void backtrack(vector<int>& nums, int ind){
        int n = nums.size();
        if(ind == n){
            allPermutation.push_back(nums);
            return;
        }

        for(int i = ind; i < n; i++){
            swap(nums[ind], nums[i]);
            backtrack(nums, ind+1);
            swap(nums[ind], nums[i]);
        }
    }

    vector<vector<int>> allPermutation;
};




/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.02
MB
Beats
30.22%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        usedNumber = vector<bool>(nums.size(), false);
        backtrack(nums, 0);
        return allPermutation;
    }

private:
    void backtrack(vector<int>& nums, int ind){
        int n = nums.size();
        if(ind == n){
            allPermutation.push_back(permutation);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!usedNumber[i]){
                usedNumber[i] = true;
                permutation.push_back(nums[i]);
                backtrack(nums, ind+1);
                permutation.pop_back();
                usedNumber[i] = false;
            }
        }
    }

    vector<vector<int>> allPermutation;
    vector<int> permutation;
    vector<bool> usedNumber;
};
#include <vector>
#include <iostream>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.24
MB
Beats
88.36%
of users with C++
*/
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int allBits = (1 << n) - 1; // 4095 '0b111111111111'

        for(int i = 1; i <= allBits; i++){
            int currSum = 0;
            int currBits = i;
            for(int j = 0; j < n; j++){
                if(currBits & 1)
                    currSum ^= nums[j];
                currBits >>= 1;
            }
            sum += currSum;
        }
    
        return sum;
    }
};




// good explanation for this approach
// https://leetcode.com/problems/sum-of-all-subset-xor-totals/solutions/1242073/java-backtracking-approach-with-explanation/
class Solution {
public:
    int xorSubsets(int index, vector<int>& nums, int val) {
        if (index == nums.size()) return val;

        // include
        int withElement = xorSubsets(index + 1, nums, val ^ nums[index]);

        // exclude
        int withoutElement  = xorSubsets(index + 1, nums, val);

        return withElement + withoutElement;
    }

    int subsetXORSum(vector<int>& nums) {
        return xorSubsets(0, nums, 0);
    }
};
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;



/*
Runtime
3
ms
Beats
96.61%
of users with C++
Memory
12.20
MB
Beats
87.16%
of users with C++
*/
/*
    Time: O(n)
    Space: O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        if(nums.size() == 2)
            return nums;
        
        int xorRes = 0;
        for(int x : nums)
            xorRes ^= x;

        int posOfLastBit = 0;
        while(((xorRes >> posOfLastBit) & 1) == 0)
            posOfLastBit++;

        int numA = 0;
        int numB = 0;

        // grouping elements into those that have a bit at a certain position and those that don't
        for(int x : nums){
            if((x >> posOfLastBit) & 1)
                numA ^= x;
            else
                numB ^= x;
        }
        
        return {numA, numB};
    }
};





/*
Runtime
7
ms
Beats
62.82%
of users with C++
Memory
13.78
MB
Beats
23.10%
of users with C++
*/
/*
    Time: O(n)
    Space: O(n)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)
            return nums;
        
        vector<int> res;
        unordered_set<int> set;

        for(int x : nums){
            if(set.count(x))
                set.erase(x);
            else
                set.insert(x);
        }

        for(int x : set)
            res.push_back(x);

        return res;
    }
};






/*
Runtime
8
ms
Beats
47.11%
of users with C++
Memory
12.63
MB
Beats
35.15%
of users with C++
*/
/*
    Time: O(n*long(n) + n)
    Space: O(1)
*/
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2)
            return nums;
        
        sort(nums.begin(), nums.end());
        vector<int> res;

        for(int i = 0; i < n; i+=2){
            if(i+1 >= n){
                res.push_back(nums[i]);
                break;
            }

            if(nums[i] != nums[i+1]){
                res.push_back(nums[i]);
                if(i == n-2){
                    res.push_back(nums[i+1]);
                    break;
                }

                if(res.size() == 2)
                    break;

                i--;
            }
        }

        return res;
    }
};
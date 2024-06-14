#include <vector>
#include <algorithm>
#include <map>
using namespace std;


/*
Runtime 84ms Beats 96.85%
Memory 74.01MB Beats 12.40%
*/
/*
    Time:  O(n)
    Space: O(n + m)   m is diff between min and max el in nums
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        auto [minV, maxV] = minmax_element(nums.begin(), nums.end());
        int xMin = *minV;
        int xMax = *maxV;
        int n = nums.size();
        int moves = 0;

        vector<int> freq(xMax - xMin + n + 1, 0);
        for(int x : nums)
            freq[x-xMin]++;
        
        int i = 0;
        for(int x = 0; i < n; x++){
            int f = freq[x];
            if(f) i++;
            if(f > 1){
                freq[x+1] += f-1;
                moves += f-1;
            }
        }

        return moves;
    }
};




/*
Runtime 115ms Beats 75.39%
Memory 68.99MB Beats 93.90%
*/
/*
    Time:  O(nlogn + n)
    Space: O(1)
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int moves = 0;
        
        for(int i = 1; i < n; i++){
            if(nums[i-1] >= nums[i]){
                moves += nums[i-1] - nums[i] + 1;
                nums[i] = nums[i-1] + 1;
            }
        }

        return moves;
    }
};




// TLE
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        map<int, int> mp;
        for(int x : nums)
            mp[x]++;

        int moves = 0;
        for(auto it = mp.begin(); it != mp.end(); it++){
            while(it->second > 1){
                it->second--;
                int nextVal = it->first + 1;
                while(mp.count(nextVal))
                    nextVal++;
                mp[nextVal] = 1;
                moves += (nextVal - it->first);
            }
        }

        return moves;
    }
};
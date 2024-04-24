#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
Runtime
65
ms
Beats
90.25%
of users with C++
Memory
49.29
MB
Beats
84.88%
of users with C++
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) 
            return 0;

        sort(nums.begin(), nums.end());

        int longestCSeq = 1;
        int currMin = nums[0];
        int currCSeq = 1;
        for(int i = 1; i < n; i++){

            if(currMin == nums[i])
                continue;

            if(currMin + 1 == nums[i]){
                currMin++;
                currCSeq++;
            }else{
                if(currCSeq > longestCSeq)
                    longestCSeq = currCSeq;
                currCSeq = 1;
                currMin = nums[i];
            }
        }

        if(currCSeq > longestCSeq)
            longestCSeq = currCSeq;

        return longestCSeq;
    }
};




/*
Runtime
782
ms
Beats
27.86%
of users with C++
Memory
74.18
MB
Beats
27.92%
of users with C++
*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();
        if(n == 0) 
            return 0;

        unordered_set<int> set;
        for(int i = 0; i < n; i++){
            set.insert(nums[i]);
        }

        int longestCSeq = 0;

        for(int i = 0; i < n; i++){
            if(set.find(nums[i]-1) == set.end()){
                int currNum = nums[i];
                int currCSeq = 1;
                while(set.find(currNum+1) != set.end()){
                    currNum++;
                    currCSeq++;
                }

                if(currCSeq > longestCSeq)
                    longestCSeq = currCSeq;
            }
        }

        return longestCSeq;
    }
};
#include <vector>
#include <string>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.08
MB
Beats
84.49%
of users with C++
*/
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        int n = nums.size();
        if(n == 0) return ranges;

        int i = 0;
        int j = 0;
        while(i < n-1){
            if(nums[i]+1 != nums[i+1]){
                addRange(ranges, i, j, nums[i], nums[j]);
                j = i;
                j++;
            }

            i++;
        }
        addRange(ranges, i, j, nums[i], nums[j]);

        return ranges;
    }

private:
    void addRange(vector<string>& ranges, int i, int j, int numsI, int numsJ){
        if(i == j){
            ranges.push_back(to_string(numsI));
        }else{
            ranges.push_back(to_string(numsJ)+"->"+to_string(numsI));
        }
    }
};
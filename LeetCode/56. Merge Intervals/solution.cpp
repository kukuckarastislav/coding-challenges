#include <vector>
#include <algorithm>
using namespace std;

/*
Runtime
17
ms
Beats
91.41%
of users with C++
Memory
22.69
MB
Beats
68.25%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 1) return intervals;

        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[0] < b[0];
        });

        vector<vector<int>> mergedIntevals;
        int start = 0;
        int i = 0;
        int rightMax = intervals[0][1];

        for(i = 1; i < n; i++){
            if(rightMax < intervals[i][0]){
                mergedIntevals.push_back(
                    {intervals[start][0], rightMax});
                start = i;
                rightMax = intervals[start][1];
            }else{
                if(intervals[i][1] > rightMax)
                    rightMax = intervals[i][1];
            }
        }

        mergedIntevals.push_back({intervals[start][0], rightMax});

        return mergedIntevals;
    }
};
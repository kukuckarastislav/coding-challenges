#include <vector>
using namespace std;

/*
Runtime
7
ms
Beats
91.67%
of users with C++
Memory
20.33
MB
Beats
85.84%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n == 0) return {newInterval};

        vector<vector<int>> ans;
        
        int i = 0;
        while(i < n){
            if(intervals[i][1] < newInterval[0]){
                ans.push_back(intervals[i]);
            }else if(intervals[i][0] > newInterval[1]){
                break;
            }else{
                if(intervals[i][0] < newInterval[0]) newInterval[0] = intervals[i][0];
                if(intervals[i][1] > newInterval[1]) newInterval[1] = intervals[i][1];
            }

            i++;
        }

        ans.push_back(newInterval);
        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
#include <vector>
#include <string>

using namespace std;


/*
Runtime
2
ms
Beats
84.79%
of users with C++
Memory
12.47
MB
Beats
55.68%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(target == 1)
            return ans;

        backtrack(candidates, target, 0, 0, 0);
        return ans;
    }

private:
    void backtrack(vector<int>& candidates, int target, int idx, int currSum, int idxLimit){
        if(idx == 21 || currSum > target) return;

        if(currSum == target){
            ans.push_back(selectedCandidates);
            return;
        }

        int n = candidates.size();
        for(int i = idxLimit; i < n; i++){
            selectedCandidates.push_back(candidates[i]);
            backtrack(candidates, target, idx + 1, currSum + candidates[i], i);
            selectedCandidates.pop_back();
        }
    }

    vector<vector<int>> ans;
    vector<int> selectedCandidates;
};
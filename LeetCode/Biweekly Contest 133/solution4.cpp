#include <vector>
#include <algorithm>
using namespace std;



class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& requirements) {
        int m = requirements.size();
        
        sort(requirements.begin(), requirements.end(), 
            [](const vector<int>& v1, const vector<int>& v2){
                return v1[0] > v2[0];
            }
        );

        int biggestEnd = requirements[0][0];
        vector<int> perm(biggestEnd + 1, 0);
        for(int i = 0; i <= biggestEnd; i++){
            perm[i] = biggestEnd - i;
        }


        return 0;
    }
};


int main(){
    
    int n = 3;
    vector<vector<int>> req = {{2,2},{4,6},{7,0},{1,1},{0,0}};
    Solution sol;
    int ans = sol.numberOfPermutations(n, req);

    return 0;
}
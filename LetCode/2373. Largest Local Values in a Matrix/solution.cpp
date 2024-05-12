#include <vector>
using namespace std;


/*
Runtime
3
ms
Beats
99.54%
of users with C++
Memory
13.32
MB
Beats
96.76%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n-2, vector<int>(n-2, 0));

        for(int i = 0; i < n-2; i++){
            for(int j = 0; j < n-2; j++){
                
                int maxVal = grid[i][j];
                for(int l = 0; l < 3; l++){
                    for(int k = 0; k < 3; k++){
                        if(grid[i+l][j+k] > maxVal)
                            maxVal = grid[i+l][j+k];
                    }
                }
                res[i][j] = maxVal;
            }
        }

        return res;
    }
};
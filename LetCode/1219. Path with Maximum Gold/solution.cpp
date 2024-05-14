#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;


/*
Runtime
22
ms
Beats
99.87%
of users with C++
Memory
9.11
MB
Beats
63.91%
of users with C++
*/

/*
before isAllGold(grid) optimization
Runtime
96
ms
Beats
88.42%
of users with C++
Memory
9.08
MB
Beats
81.32%
of users with C++
*/
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {

        int maxGold = isAllGold(grid);
        if(maxGold)
            return maxGold;
        
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j]){
                    int gold = getGold(grid, i, j, 0);
                    if(gold > maxGold) 
                        maxGold = gold;        
                }

            }
        }
        
        return maxGold;
    }

    int getGold(vector<vector<int>>& grid, int i, int j, int gold){

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return gold;

        if(grid[i][j] <= 0)
            return gold;

        int tempGold = grid[i][j];
        grid[i][j] = 0;
        gold += tempGold;

        int maxGold = getGold(grid, i-1, j, gold); 
        maxGold = max(maxGold, getGold(grid, i, j-1, gold)); 
        maxGold = max(maxGold, getGold(grid, i+1, j, gold)); 
        maxGold = max(maxGold, getGold(grid, i, j+1, gold));

        grid[i][j] = tempGold;

        return maxGold;
    }

    int isAllGold(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]) sum += grid[i][j];
                else return 0;
            }
        }
        return sum;
    }
};


int main(){

    vector<vector<int>> grid({
        {0,0,0,22,0,24},
        {34,23,18,0,23,2},
        {11,39,20,12,0,0},
        {39,8,0,2,0,1},
        {19,32,26,20,20,30},
        {0,38,26,0,29,31}
    });

    Solution sol;
    int gold = sol.getMaximumGold(grid);

    return 0;
}



/////// 

/*
Runtime
467
ms
Beats
6.31%
of users with C++
Memory
10.69
MB
Beats
15.13%
of users with C++
*/
class Solution {
public:
    vector<int> path;
    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxGold = 0;
        
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j]){
                    path.clear();
                    int gold = getGold(grid, i, j, 0);
                    if(gold > maxGold) 
                        maxGold = gold;        
                }

            }
        }
        
        return maxGold;
    }

    int getGold(vector<vector<int>>& grid, int i, int j, int gold){

        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return gold;

        int cord = cti(i,j);

        if(grid[i][j] <= 0 || isVisited(cord))
            return gold;

        path.push_back(cord);
        gold += grid[i][j];

        int maxGold = getGold(grid, i-1, j, gold);
        while(path.back() != cord){
            path.pop_back();
        } 
            
        maxGold = max(maxGold, getGold(grid, i, j-1, gold));
        while(path.back() != cord){
            path.pop_back();
        } 

        maxGold = max(maxGold, getGold(grid, i+1, j, gold));
        while(path.back() != cord){
            path.pop_back();
        } 

        maxGold = max(maxGold, getGold(grid, i, j+1, gold));
        while(path.back() != cord){
            path.pop_back();
        }

        return maxGold;
    }

    int cti(int i, int j){
        return i*100 + j;
    }

    bool isVisited(int cord){
        for(int c :path)
            if(c == cord) 
                return true;
        return false;
    }
};
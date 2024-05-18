#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    sinkIslands(grid, i,j);
                    islands++;
                }
            }
        }

        return islands;
    }

    void sinkIslands(vector<vector<char>>& grid, int i, int j){

        grid[i][j] = '0';

        if(i-1 >= 0 && grid[i-1][j] == '1') 
            sinkIslands(grid, i-1, j);
        
        if(i+1 < grid.size() && grid[i+1][j] == '1') 
            sinkIslands(grid, i+1, j);
        
        if(j-1 >= 0 && grid[i][j-1] == '1')
            sinkIslands(grid, i, j-1);

        if(j+1 < grid[0].size() && grid[i][j+1] == '1')
            sinkIslands(grid, i, j+1);
    }
};
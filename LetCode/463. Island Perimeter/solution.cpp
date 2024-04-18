class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int islands = 0, neighbours = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    islands++;
                    if (i < n-1 && grid[i+1][j]) neighbours++;
                    if (j < m-1 && grid[i][j+1]) neighbours++;
                }
            }
        }

        return islands * 4 - neighbours * 2;
    }
};




class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int peri = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j]){

                    if(i-1 >= 0){ 
                        if(grid[i-1][j] == 0) peri++;
                    }else peri++;

                    if(i+1 < n){
                        if(grid[i+1][j] == 0) peri++;
                    }else peri++;

                    if(j-1 >= 0){
                        if(grid[i][j-1] == 0) peri++;
                    }else peri++;
                    
                    if(j+1 < m){
                        if(grid[i][j+1] == 0) peri++;
                    }else peri++;
                }
            }
        }

        return peri;
    }
};
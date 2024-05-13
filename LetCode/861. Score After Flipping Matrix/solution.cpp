#include <vector>
#include <iostream>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.13
MB
Beats
75.07%
of users with C++
*/
class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        
        int n = grid.size();
        for(int i = 0; i < n; i++){
            if(grid[i][0] == 0){
                flipRow(grid[i]);
            }
        }
 
        int m = grid[0].size();
        for(int j = 0; j < m; j++){
            if(countOnes(grid, j) <= n/2){
                flipCol(grid, j);
            }
        }
        
        return getScore(grid);
    }

    void flipRow(vector<int>& row){
        int n = row.size();
        for(int i = 0; i < n; i++){
            if(row[i]) row[i] = 0;
            else row[i] = 1;
        }
    }

    int countOnes(vector<vector<int>>& grid, int col){
        int ones = 0;
        int n = grid.size();
        for(int i = 0; i < n; i++){
            if(grid[i][col])
                ones++;
        }
        return ones;
    }

    void flipCol(vector<vector<int>>& grid, int col){
        int n = grid.size();
        for(int i = 0; i < n; i++){
            if(grid[i][col]) grid[i][col] = 0;
            else grid[i][col] = 1;
        }
    }

    int getScore(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            int num = 0;
            for(int j = 0; j < m-1; j++){
                num += grid[i][j];
                num <<= 1;
            }
            num += grid[i][m-1];
            sum += num;
        }
        return sum;
    }

    void printGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
};

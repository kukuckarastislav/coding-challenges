#include <vector>

using namespace std;


class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        int b = 0;
        int w = 0;
        for(int i = 0; i <= 1; i++){
            for(int j = 0; j <= 1; j++){
                w = 0;
                b = 0;

                if(grid[i][j] == 'W') w++;
                else b++;

                if(grid[i+1][j] == 'W') w++;
                else b++;

                if(grid[i][j+1] == 'W') w++;
                else b++;

                if(grid[i+1][j+1] == 'W') w++;
                else b++;

                if(b >= 3 || w >= 3) return true;
            
            }
        }

        return false;
    }
};
#include <vector>

using namespace std;


class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        vector<int> onesInCol(m, 0);
        vector<int> onesInRow(n, 0);
        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) sum++;
            }
            onesInRow[i] = sum;
        }
        for(int j = 0; j < m; j++){
            int sum = 0;
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1) sum++;
            }
            onesInCol[j] = sum;
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1){
                    ans += (onesInRow[i]-1)*(onesInCol[j]-1);
                }

            }
        }

        return ans;
    }
};




///// TLE

#include <vector>

using namespace std;


class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        long long ans = 0;

        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(grid[i][j] == 1){

                    int onesInRowLeft = 0;
                    int onesInRowRight = 0;
                    int onesInColUp = 0;
                    int onesInColDown = 0;

                    for(int l = 0; l < m; l++){
                        if(l < j){
                            if(grid[i][l] == 1) onesInRowLeft++;
                        }else if(l > j){
                            if(grid[i][l] == 1) onesInRowRight++;
                        }
                    }

                    for(int k = 0; k < n; k++){
                        if(k < i){
                            if(grid[k][j] == 1) onesInColUp++;
                        }else if(k > i){
                            if(grid[k][j] == 1) onesInColDown++;
                        }
                    }
                    ans += onesInRowLeft*onesInColUp + onesInRowLeft*onesInColDown + onesInRowRight*onesInColUp + onesInRowRight*onesInColDown ;
                }

            }
        }

        return ans;
    }
};
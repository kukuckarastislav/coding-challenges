class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        bool zeroInCol = false;
        bool zeroInRow = false;
        
        // check first row
        for(int i = 0; i < m; i++){
            if(matrix[i][0] == 0){
                zeroInRow = true;
                break;
            }
        }
        
        // check first col
        for(int j = 0; j < n; j++){
            if(matrix[0][j] == 0){
                zeroInCol = true;
                break;
            }
        }

        // check sumatrix (m-1)x(n-1)
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        // for each 0 in first row we will set 0 to whole col
        for(int i = 1; i < m; i++){
            if(matrix[i][0] == 0){
                for(int j = 1; j < n; j++){
                    matrix[i][j] = 0;
                }
            }
        }

        // for each 0 in first col we sill set 0 to whole row
        for(int j = 1; j < n; j++){
            if(matrix[0][j] == 0){
                for(int i = 1; i < m; i++){
                    matrix[i][j] = 0;
                }
            }
        }

        if(zeroInCol){
            for(int j = 0; j < n; j++){
                matrix[0][j] = 0;
            }
        }

        if(zeroInRow){
            for(int i = 0; i < m; i++){
                matrix[i][0] = 0;
            }
        }

    }
};
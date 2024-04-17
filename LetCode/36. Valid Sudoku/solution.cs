/*
Runtime
82
ms
Beats
94.56%
of users with C#
Memory
46.62
MB
Beats
87.27%
of users with C#
*/
public class Solution {
    public bool IsValidSudoku(char[][] board) {
        int[] occ = {0,0,0, 0,0,0, 0,0,0};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[i][j];
                if(c != '.'){
                    if(occ[(c - 49)]++ > 0){
                        return false;
                    }
                } 
            }
            for(int j = 0; j < 9; j++) occ[j] = 0;
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                char c = board[j][i];
                if(c != '.'){
                    if(occ[(c - 49)]++ > 0){
                        return false;
                    }
                } 
            }
            for(int j = 0; j < 9; j++) occ[j] = 0;
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        char c = board[i*3+k][j*3+l];
                        if(c != '.'){
                            if(occ[(c - 49)]++ > 0){
                                return false;
                            }
                        } 
                    }
                }
                for(int x = 0; x < 9; x++) occ[x] = 0;
            }
        }

        return true;
    }
}
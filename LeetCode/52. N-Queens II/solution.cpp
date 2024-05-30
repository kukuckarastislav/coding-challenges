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
8.20
MB
Beats
37.91%
of users with C++
*/
class Solution {
public:
    int totalNQueens(int n) {
        if(n == 1) return 1;
        if(n <= 3) return 0;

        col = vector<bool>(n, false);
        posDiag = vector<bool>(2*n - 1, false);
        negDiag = vector<bool>(2*n - 1, false);

        backtrack(n, 0);

        return res;
    }

private:

    void backtrack(int n, int idx){
        if(idx == n){
            res++;
            return;
        }

        for(int i = 0; i < n; i++){
            if(!col[i] && !posDiag[idx + i] && !negDiag[idx - i + n - 1]){
                col[i] = true;
                posDiag[idx + i] = true;
                negDiag[idx - i + n - 1] = true;
                backtrack(n, idx + 1);
                col[i] = false;
                posDiag[idx + i] = false;
                negDiag[idx - i + n - 1] = false;
            }
        }
    }

    int res = 0;
    vector<bool> col;
    vector<bool> posDiag;
    vector<bool> negDiag;
};







/*
Runtime
234
ms
Beats
5.04%
of users with C++
Memory
7.42
MB
Beats
54.33%
of users with C++
*/
// Solution that can visualize board 
class Solution {
public:
    int totalNQueens(int n) {
        if(n == 1) return 1;
        if(n <= 3) return 0;

        board = vector<vector<char>>(n, vector<char>(n, 0));
        backtrack(n, 0);
        return res;
    }

private:
    vector<vector<char>> board;
    int numOfQueen = 0;
    int res = 0;

    void backtrack(int n, int idx){
        if(numOfQueen > n) return;

        if(idx == n*n){
            if(numOfQueen == n){
                res++;
                printBoard();
            }
            return;
        }

        // exclude Q on pos i, j
        backtrack(n, idx+1);

        int i = idx / n;
        int j = idx % n;
        // include Q on pos i, j if is possible
        if(board[i][j] == 0){
            setQueen(i, j);
            numOfQueen++;
            backtrack(n, idx+1);
            numOfQueen--;
            removeQueen(i, j);
        }

    }

    void setQueen(int i, int j){
        updateBoard(i, j, 1);
    }

    void removeQueen(int i, int j){
        updateBoard(i, j, -1);
    }

    void updateBoard(int i, int j, int action){
        int n = board.size();
        
        for(int k = 0; k < n; k++){
            board[k][j] += action;
            board[i][k] += action;
        }

        int ii = i-1;
        int jj = j-1;
        while(ii >= 0 && jj >= 0){  // left top
            board[ii][jj] += action;
            ii--; 
            jj--;
        }

        ii = i-1; 
        jj = j+1;
        while(ii >= 0 && jj < n){   // right top
            board[ii][jj] += action;
            ii--;
            jj++;
        }

        ii = i+1; 
        jj = j+1;
        while(ii < n && jj < n){   // right bottom
            board[ii][jj] += action;
            ii++;
            jj++;
        }

        ii = i+1; 
        jj = j-1;
        while(ii < n && jj >= 0){   // left bottom
            board[ii][jj] += action;
            ii++;
            jj--;
        }

        if(action == 1)
            board[i][j] = -1;
        else if(action == -1)
            board[i][j] = 0;
    }

    void printBoard(){
        int n = board.size();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char c = board[i][j];
                if(c == 0)
                    cout << " ";
                else if(c == -1)
                    cout << "Q";
                else if(c > 0)
                    cout << "X";
            }
            cout << endl;
        }
        cout << endl;
    }
};
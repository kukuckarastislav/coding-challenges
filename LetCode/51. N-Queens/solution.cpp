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
10.72
MB
Beats
37.15%
of users with C++
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) return {{"Q"}};
        if(n <= 3) return {};

        col = vector<bool>(n, false);
        posDiag = vector<bool>(2*n - 1, false);
        negDiag = vector<bool>(2*n - 1, false);
        board = vector<string>(n, string(n,'.'));

        backtrack(n, 0);

        return ans;
    }

private:

    void backtrack(int n, int idx){
        if(idx == n){
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < n; i++){
            if(!col[i] && !posDiag[idx + i] && !negDiag[idx - i + n - 1]){
                col[i] = true;
                posDiag[idx + i] = true;
                negDiag[idx - i + n - 1] = true;
                board[idx][i] = 'Q';
                backtrack(n, idx + 1);
                col[i] = false;
                posDiag[idx + i] = false;
                negDiag[idx - i + n - 1] = false;
                board[idx][i] = '.';
            }
        }
    }

    vector<vector<string>> ans;
    vector<string> board;
    vector<bool> col;
    vector<bool> posDiag;
    vector<bool> negDiag;
};





/*
Runtime
228
ms
Beats
5.11%
of users with C++
Memory
12.71
MB
Beats
20.73%
of users with C++
*/
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        if(n == 1) return {{"Q"}};
        if(n <= 3) return {};

        board = vector<vector<char>>(n, vector<char>(n, 0));
        backtrack(n, 0);
        return allBoards;
    }

private:
    vector<vector<char>> board;
    vector<vector<string>> allBoards;
    int numOfQueen = 0;

    void backtrack(int n, int idx){
        if(numOfQueen > n) return;

        if(idx == n*n){
            if(numOfQueen == n){
                addBoard();
                //printBoard();
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

    void addBoard(){
        int n = board.size();
        vector<string> newBoard(n, string(n, '.'));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == -1){
                    newBoard[i][j] = 'Q';
                }
            }
        }
        allBoards.push_back(newBoard);
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
#include <vector>
#include <queue>
#include <iostream>
#include <unordered_set>
using namespace std;




/*
Runtime
12
ms
Beats
70.73%
of users with C++
Memory
15.00
MB
Beats
98.75%
of users with C++
*/
/*
    tracking visited cells with vector<bool>
    counting moves with each iteration over que size
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        if(board[0][0] != -1) return -1;

        auto getCell = [&board, &n](int num) -> int {
            if(num < 1 || num > n*n) return num;
            num--;
            int x = n - 1 - (num / n);
            int y = ((n-x) % 2)? (num % n) : n-1-(num % n);
            if(board[x][y] != -1) return board[x][y];
            else return num+1;
        };


        vector<bool> visitedCells(n*n +1, false);
        queue<int> que;
        que.push(1);
        visitedCells[1] = true;

        int minMoves = 0;

        while(!que.empty()){

            int qsize = que.size();
            while(qsize--){

                int currCell = que.front(); que.pop();

                if(currCell == n*n)
                    return minMoves;

                for(int dice = 6; dice >= 1; dice--){ 
                    if(currCell + dice > n*n) 
                        continue;

                    int nextCell = getCell(currCell + dice);
                    if(!visitedCells[nextCell]){
                        que.push(nextCell);
                        visitedCells[nextCell] = true;
                    }
                }
            }

            minMoves++;
        }
        
        return -1;
    }
};




/*
Runtime
11
ms
Beats
78.85%
of users with C++
Memory
16.34
MB
Beats
38.70%
of users with C++
*/
/*
    tracking visited cells with vector<bool>
    counting moves with inc depth for each next cell
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        if(board[0][0] != -1) return -1;

        auto getCell = [&board, &n](int num) -> int {
            if(num < 1 || num > n*n) return num;
            num--;
            int x = n - 1 - (num / n);
            int y = ((n-x) % 2)? (num % n) : n-1-(num % n);
            if(board[x][y] != -1) return board[x][y];
            else return num+1;
        };


        vector<bool> visitedCells(n*n, false);
        queue<pair<int, int>> que;
        que.push({1, 0});

        while(que.size()){
            auto [currCell, depth] = que.front(); que.pop();

            if(currCell == n*n)
                return depth;

            if(visitedCells[currCell])
                continue;
            
            visitedCells[currCell] = true;

            for(int dice = 6; dice >= 1; dice--){ 
                if(currCell + dice > n*n) 
                    continue;

                que.push({getCell(currCell + dice), depth + 1});
            }
        }
        
        return -1;
    }
};





/*
Runtime
18
ms
Beats
34.74%
of users with C++
Memory
18.95
MB
Beats
15.19%
of users with C++
*/
/*
    tracking visited cells with unordered_set
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();

        if(board[0][0] != -1) return -1;

        auto getCell = [&board, &n](int num) -> int {
            if(num < 1 || num > n*n) return num;
            num--;
            int x = n - 1 - (num / n);
            int y = ((n-x) % 2)? (num % n) : n-1-(num % n);
            if(board[x][y] != -1) return board[x][y];
            else return num+1;
        };


        unordered_set<int> visitedCells;
        queue<pair<int, int>> que;
        que.push({1, 0});

        while(que.size()){
            auto [currCell, depth] = que.front(); que.pop();

            if(currCell == n*n)
                return depth;

            if(visitedCells.count(currCell))
                continue;
            
            visitedCells.insert(currCell);

            for(int dice = 6; dice >= 1; dice--){ 
                if(currCell + dice > n*n) 
                    continue;

                que.push({getCell(currCell + dice), depth + 1});
            }
        }
        
        return -1;
    }
};


int main(){

    vector<vector<int>> board({
        {-1,-1,19,10,-1},
        {2,-1,-1,6,-1},
        {-1,17,-1,19,-1},
        {25,-1,20,-1,-1},
        {-1,-1,-1,-1,15}
    });

    Solution sol;
    int x = sol.snakesAndLadders(board);
    
    return 0;
}
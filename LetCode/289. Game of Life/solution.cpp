class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        
        vector<vector<int>> newBoard(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                newBoard[i][j] = getNextCellState(board, i, j);
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = newBoard[i][j];
            }
        }
    }

    int getNextCellState(vector<vector<int>>& board, int i, int j){
        int n = board.size();
        int m = board[0].size();
        int liveNeighbors = 0;

        if(i-1 >= 0)                liveNeighbors += board[i-1][j];
        if(j-1 >= 0)                liveNeighbors += board[i][j-1];
        if(i+1 < n)                 liveNeighbors += board[i+1][j];
        if(j+1 < m)                 liveNeighbors += board[i][j+1];
        if(i-1 >= 0 && j-1 >= 0)    liveNeighbors += board[i-1][j-1];
        if(i+1 < n && j+1 < m)      liveNeighbors += board[i+1][j+1];
        if(i+1 < n && j-1 >= 0)     liveNeighbors += board[i+1][j-1];
        if(i-1 >= 0 && j+1 < m)     liveNeighbors += board[i-1][j+1];

        if(liveNeighbors < 2)                   return 0;
        if(liveNeighbors <= 3 && board[i][j])   return 1;
        if(liveNeighbors == 3)                  return 1;
        return 0;
    }
};
class Solution {
public:

    bool findWord(vector<vector<char>>& board, string& word, int depth, int i, int j){

        if(board[i][j] == '_')
            return false;

        if(word[depth] != board[i][j])
            return false;

        char temp = board[i][j];
        board[i][j] = '_';
        
        depth++;

        if(depth == word.size())
            return true;

        int m = board.size();
        int n = board[0].size();

        bool found = false;
        if(i - 1 >= 0)           found = findWord(board, word, depth, i-1, j);
        if(!found && j - 1 >= 0) found = findWord(board, word, depth, i, j-1);
        if(!found && i + 1 < m)  found = findWord(board, word, depth, i+1, j);
        if(!found && j + 1 < n)  found = findWord(board, word, depth, i, j+1);

        board[i][j] = temp;

        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == word[0]){
                    if(findWord(board, word, 0, i, j)) return true;
                }
            }
        }

        return false;
    }
};
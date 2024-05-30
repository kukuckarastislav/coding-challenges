#include <vector>
#include <string>
#include <unordered_set>
using namespace std;




/*
    TLE - Time Limit Exceeded
    ===============================================================================
    The solution works but it is slow because we are creating a trie over the board
*/
struct Node {
    char c;
    Node* nextNodes[4] = {nullptr};

    Node(char _c){
        c = _c;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;

        for(string& word : words){
            depthLimit = max(depthLimit, (int)word.size());
        }

        trie = vector<vector<Node*>>(26);
        populateTrieWithBoard(board);

        for(string& word : words){
            if(isWordPresentOnBoard(word)){
                res.push_back(word);
            }
        }
        
        return res;
    }

private:
    vector<vector<Node*>> trie;
    unordered_set<char> usedChars;
    int depthLimit = 0;
    int dx[4] = {-1,  0, 1, 0};
    int dy[4] = { 0, -1, 0, 1};


    bool isWordPresentOnBoard(string& word){

        for(char c : word){
            if(!usedChars.count(c))
                return false;
        }
        
        for(Node* node : trie[word[0]-'a']){
            if(isWordPresentInTrie(node, word, 0))
                return true;
        }

        return false;
    }

    bool isWordPresentInTrie(Node* node, string& word, int i){
        if(i >= word.size())
            return true;

        if(node->c != word[i])
            return false;

        for(int k = 0; k < 4; k++){
            if(node->nextNodes[k] && isWordPresentInTrie(node->nextNodes[k], word, i+1))
                return true;
        }

        return false;
    }

    void populateTrieWithBoard(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                char c = board[i][j];
                trie[c-'a'].push_back(constructTrieNode(board, visited, i, j, 0));
                if(!usedChars.count(c))
                    usedChars.insert(c);
            }
        }
    }

    Node* constructTrieNode(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, int depth){
        int n = board.size();
        int m = board[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m || visited[i][j] || depth > depthLimit)
            return nullptr;        

        visited[i][j] = true;

        Node* newNode = new Node(board[i][j]);
        for(int k = 0; k < 4; k++){
            int ii = i + dx[k];
            int jj = j + dy[k];
            newNode->nextNodes[k] = constructTrieNode(board, visited, ii, jj, depth+1);
        }

        visited[i][j] = false;

        return newNode;
    }
};
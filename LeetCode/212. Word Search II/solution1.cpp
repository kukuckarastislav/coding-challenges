#include <vector>
#include <string>
#include <unordered_set>
using namespace std;



/*
Runtime
1369
ms
Beats
33.11%
of users with C++
Memory
18.88
MB
Beats
65.38%
of users with C++
*/
struct TrieNode {
    bool isWord = false;
    TrieNode* nextNodes[26] = {nullptr};
};

struct Trie {
    TrieNode* head = nullptr;

    Trie(){
        head = new TrieNode();
    }

    void addWord(string& word){
        TrieNode* it = head;
        for(char c : word){
            if(!it->nextNodes[c-'a'])
                it->nextNodes[c-'a'] = new TrieNode();
            
            it = it->nextNodes[c-'a'];
        }

        if(it)
            it->isWord = true;
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for(string& word : words){
            trie.addWord(word);
            depthLimit = max(depthLimit, (int)word.size());
        }

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                dfs(board, trie.head, i, j, "", 0);
            }
        }

        return res;
    }

private:
    Trie trie;
    vector<string> res;
    int depthLimit = 0;

    int dx[4] = {-1,  0, 1, 0};
    int dy[4] = { 0, -1, 0, 1};

    void dfs(vector<vector<char>>& board, TrieNode* node, int i, int j, string word, int depth){
        if(depth > depthLimit)
            return;

        int n = board.size();
        int m = board[0].size();

        if(i < 0 || i >= n || j < 0 || j >= m)
            return;

        char c = board[i][j];

        if(c == '#' || !node->nextNodes[c-'a'])
            return;

        board[i][j] = '#';
        word += c;
        node = node->nextNodes[c-'a'];
        
        if(node->isWord){
            res.push_back(word);
            node->isWord = false; 
        }

        for(int k = 0; k < 4; k++){
            int ii = i + dx[k];
            int jj = j + dy[k];
            dfs(board, node, ii, jj, word, depth+1);
        }

        board[i][j] = c;
    }
};


int main(){

    vector<vector<char>> board({{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}});
    vector<string> words({"oath","pea","eat","rain"});
    Solution sol;
    auto res = sol.findWords(board, words);

    return 0;
}
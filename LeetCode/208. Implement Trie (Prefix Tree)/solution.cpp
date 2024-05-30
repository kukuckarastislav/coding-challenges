#include <string>
#include <vector>
using namespace std;

/*
Runtime
48
ms
Beats
62.84%
of users with C++
Memory
51.62
MB
Beats
17.84%
of users with C++
*/
class TrieNode{
public:
    TrieNode(){
        wordEnding = false;
        nextChars = vector<TrieNode*>(26, nullptr);
    }

    TrieNode(bool _wordEnding){
        wordEnding = _wordEnding;
        nextChars = vector<TrieNode*>(26, nullptr);
    }

    TrieNode* getNextTrieNode(char nextChar){
        if(nextChar < 'a' or nextChar > 'z') return nullptr;
        return nextChars[nextChar-'a'];
    }

    TrieNode* setNextTrieNode(char nextChar){
        if(nextChar < 'a' or nextChar > 'z') return nullptr;

        TrieNode* newTrieNode = new TrieNode();
        nextChars[nextChar-'a'] = newTrieNode;
        return newTrieNode;
    }

    void setWordEnding(bool flag){
        wordEnding = flag;
    }

    bool isWordEnding(){
        return wordEnding;
    }

private:
    bool wordEnding;
    vector<TrieNode*> nextChars;
};


class Trie {
private:
    TrieNode* head = nullptr;

public:
    Trie() {
        head = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* currTrieNode = head;
        for(char c : word){
            if(!currTrieNode->getNextTrieNode(c))
                currTrieNode = currTrieNode->setNextTrieNode(c);
            else
                currTrieNode = currTrieNode->getNextTrieNode(c);
        }

        currTrieNode->setWordEnding(true);
    }
    
    bool search(string word) {
        TrieNode* currTrieNode = head;
        for(char c : word){
            if(!currTrieNode->getNextTrieNode(c))
                return false;

            currTrieNode = currTrieNode->getNextTrieNode(c);
        }

        return currTrieNode->isWordEnding();
    }
    
    bool startsWith(string prefix) {
        TrieNode* currTrieNode = head;
        for(char c : prefix){
            if(!currTrieNode->getNextTrieNode(c))
                return false;
            
            currTrieNode = currTrieNode->getNextTrieNode(c);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main(){

    Trie trie;
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True



    return 0;
}
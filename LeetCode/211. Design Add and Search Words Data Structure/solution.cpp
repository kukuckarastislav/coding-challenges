#include <string>
#include <cmath>
using namespace std;


/*
Runtime
426
ms
Beats
97.38%
of users with C++
Memory
555.06
MB
Beats
54.65%
of users with C++
*/

struct Node {
    bool wordExist;
    Node* AZnodes[26] = {nullptr};
};


class WordDictionary {
private:
    Node* head = nullptr;
    int longestWord = 0;

public:
    WordDictionary() {
        head = new Node();    
    }
    
    void addWord(string word) {
        Node* it = head;
        for(char c : word){
            if(!it->AZnodes[c-'a'])
                it->AZnodes[c-'a'] = new Node();
            
            it = it->AZnodes[c-'a'];
        }

        if(it && it != head){
            it->wordExist = true;
            longestWord = max(longestWord, (int)word.size());
        }
    }
    
    bool search(string word) {
        if(word.size() > longestWord)
            return false;

        return _search(word, head, 0);
    }

private:

    bool _search(string& word, Node* startNode, int startIndex){
        if(!startNode)
            return false;

        Node* it = startNode;
        int n = word.size();
        for(int i = startIndex; i < n; i++){
            char c = word[i];

            if(c == '.'){
                for(int j = 0; j < 26; j++){
                    if(_search(word, it->AZnodes[j], i+1))
                        return true;
                }
                
                return false;
            }

            if(!it->AZnodes[c-'a'])
                return false;

            it = it->AZnodes[c-'a'];
        }

        return it->wordExist;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
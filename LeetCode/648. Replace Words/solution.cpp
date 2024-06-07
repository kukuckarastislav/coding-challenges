#include <vector>
#include <string>
using namespace std;

/*
Runtime
54
ms
Beats
96.51%
of users with C++
Memory
68.76
MB
Beats
78.37%
of users with C++
*/

struct TrieNode {
    bool isWord = false;
    TrieNode* next[26] = {nullptr};
};


class Trie {
    TrieNode* head;
    TrieNode* curr;
public:

    Trie(vector<string>& dictionary){
        head = new TrieNode();
        curr = head;

        for(const string& word : dictionary){
            insert(word);
        }
    }

    void insert(const string& word){
        TrieNode* it = head;
        for(char c : word){
            if(!it->next[c-'a'])
                it->next[c-'a'] = new TrieNode();

            it = it->next[c-'a'];
        }

        it->isWord = true;
    }


    bool next(char c){
        curr = curr->next[c-'a'];
        return curr != nullptr;
    }

    bool isCurrWord(){
        return curr->isWord;
    }

    void reset(){
        curr = head;
    }
};




class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string res = "";
        int n = sentence.size();
        Trie trie(dictionary);

        int i = 0;
        while(i < n){

            if(sentence[i] == ' '){
                res += ' ';
                trie.reset();
            }else if(trie.next(sentence[i])){
                res += sentence[i];
                if(trie.isCurrWord()){
                    while(i < n && sentence[i] != ' ') i++;
                    res += ' ';
                    trie.reset();
                }
            }else{
                while(i < n && sentence[i] != ' '){
                    res += sentence[i];
                    i++;
                }
                res += ' ';
                trie.reset();
            }
        
            
            i++;
        }

        if(res.back() == ' ')
            res.pop_back();
        
        return res;
    }
};
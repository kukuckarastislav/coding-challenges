#include <vector>
#include <string>
#include <unordered_set>
#include <bits/stdc++.h>
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
9.20
MB
Beats
49.07%
of users with C++
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        result = vector<string>();
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());

        string sentence = "";
        
        backtrack(s, sentence, 0, 1);

        return result;
    }

private:

    unordered_set<string> wordSet;
    vector<string> result;

    void backtrack(string& s, string& sentence, int startIndex, int offset){
        string word = s.substr(startIndex, offset);

        if(startIndex + offset == s.size()){
            if(wordSet.count(word)){
                sentence += word;
                result.push_back(sentence);
            }
            return;
        }

        if(wordSet.count(word)){
            string newSentence = sentence + word + " ";
            backtrack(s, newSentence, startIndex+offset, 1);
        }

        backtrack(s, sentence, startIndex, offset + 1);
    }
};




/*
Runtime
282
ms
Beats
6.50%
of users with C++
Memory
48.15
MB
Beats
5.09%
of users with C++
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        result = vector<string>();
        wordSet = unordered_set<string>(wordDict.begin(), wordDict.end());

        string strWithSpaces = "";
        for(char c : s){
            strWithSpaces += c;
            strWithSpaces += ' ';
        }
        strWithSpaces.pop_back(); // removing last space
        
        string sentence = "";
        backtrack(strWithSpaces, sentence, 0);

        return result;
    }

private:

    unordered_set<string> wordSet;
    vector<string> result;

    void backtrack(string& strWithSpaces, string& sentence, int i){
        if(i == strWithSpaces.size()){   
            tryToUpdateFinalResult(sentence);
            return;
        }

        if(i % 2 == 1){
            // add space include or exclude
            backtrack(strWithSpaces, sentence, i+1);

            sentence.push_back(strWithSpaces[i]);
            backtrack(strWithSpaces, sentence, i+1);
            sentence.pop_back();
        }else{
            // letter always include
            sentence.push_back(strWithSpaces[i]);
            backtrack(strWithSpaces, sentence, i+1);
            sentence.pop_back();
        }
    }

    void tryToUpdateFinalResult(string& sentence){
        // cout << sentence << endl;
        stringstream ss(sentence);
        string word;
        while(getline(ss, word, ' ')){
            if(!wordSet.count(word)){
                return;
            }
        }

        result.push_back(sentence);
    }
};
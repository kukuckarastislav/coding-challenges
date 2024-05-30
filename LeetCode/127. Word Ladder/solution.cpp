#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;





/*
Runtime
76
ms
Beats
62.38%
of users with C++
Memory
20.62
MB
Beats
40.67%
of users with C++
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int m = beginWord.size();

        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if(!wordSet.count(endWord))
            return 0;


        int numOfTransformation = 1;
        queue<string> que;
        unordered_set<string> visited;

        que.push(beginWord);
        visited.insert(beginWord);

        while(que.size()){

            int qsize = que.size();
            while(qsize--){
                string currWord = que.front(); que.pop();

                if(currWord == endWord)
                    return numOfTransformation;

                for(int i = 0; i < m; i++){
                    string nextWord = currWord;
                    for(char c = 'a'; c <= 'z'; c++){
                        nextWord[i] = c;
                        
                        if(wordSet.count(nextWord) and !visited.count(nextWord)){
                            que.push(nextWord);
                            visited.insert(nextWord);
                        }
                    }
                }
            }

            numOfTransformation++;
        }

        return 0;
    }

private:

    bool canTransform(const string& text1, const string& text2){
        int diff = 0;
        int n = text1.size();
        for(int i = 0; i < n; i++){
            if(text1[i] != text2[i]){
                diff++;
            }
        }

        return diff == 1;
    }
};





/*
Runtime
747
ms
Beats
23.16%
of users with C++
Memory
18.07
MB
Beats
96.43%
of users with C++
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();

        if(!isEndWordInWordList(wordList, endWord))
            return 0;


        int numOfTransformation = 1;
        queue<string> que;
        unordered_set<string> visited;

        que.push(beginWord);
        visited.insert(beginWord);

        while(que.size()){

            int qsize = que.size();
            while(qsize--){
                string currWord = que.front(); que.pop();

                if(currWord == endWord)
                    return numOfTransformation;

                for(string& nextWord : wordList){
                    if(canTransform(currWord, nextWord) and !visited.count(nextWord)){
                        que.push(nextWord);
                        visited.insert(nextWord);
                    }
                }
                
            }

            numOfTransformation++;
        }

        return 0;
    }

private:

    bool canTransform(const string& text1, const string& text2){
        int diff = 0;
        int n = text1.size();
        for(int i = 0; i < n; i++){
            if(text1[i] != text2[i]){
                diff++;
            }
        }

        return diff == 1;
    }

    bool isEndWordInWordList(vector<string>& wordList, string& endWord){
        int n = wordList.size();
        for(int i = 0; i < n; i++){
            if(wordList[i] == endWord)
                return true;
        }

        return false;
    }
};



/*
Runtime
861
ms
Beats
21.61%
of users with C++
Memory
39.84
MB
Beats
13.21%
of users with C++
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        
        unordered_map<string, vector<string>> graph;
        wordList.push_back(beginWord);
        for(int i = 0; i <= n; i++){   
            for(int j = i+1; j <= n; j++){
                if(canTransform(wordList[i], wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }
        wordList.pop_back(); // removing beginWord

        if(graph[endWord].size() == 0)
            return 0;


        int numOfTransformation = 1;
        queue<string> que;
        unordered_set<string> visited;

        que.push(beginWord);
        visited.insert(beginWord);

        while(que.size()){

            int qsize = que.size();
            while(qsize--){
                string currWord = que.front(); que.pop();

                if(currWord == endWord)
                    return numOfTransformation;

                for(string& nextWord : graph[currWord]){
                    if(!visited.count(nextWord)){
                        que.push(nextWord);
                        visited.insert(nextWord);
                    }
                }
                
            }

            numOfTransformation++;
        }

        return 0;
    }

    bool canTransform(const string& text1, const string& text2){
        int diff = 0;
        int n = text1.size();
        for(int i = 0; i < n; i++){
            if(text1[i] != text2[i]){
                diff++;
            }
        }

        return diff == 1;
    }
};
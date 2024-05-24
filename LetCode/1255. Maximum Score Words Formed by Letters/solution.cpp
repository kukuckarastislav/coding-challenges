#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;




/*
Runtime
4
ms
Beats
80.97%
of users with C++
Memory
11.47
MB
Beats
97.86%
of users with C++
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(char c : letters) 
            letterCount[c-'a']++;

        backtrack(words, score, 0);

        return maxScore;
    }

private:
    int maxScore = 0;
    int letterCount[26] = {0};
    int usedLetterCount[26] = {0};

    void backtrack(vector<string>& words, vector<int>& score, int i)
    {
        if(i == words.size()){
            updateMaxScore(score);
            return;
        }

        // exclude
        backtrack(words, score, i+1);

        // include 
        for(char c : words[i])
            usedLetterCount[c-'a']++;
        backtrack(words, score, i+1);
        for(char c : words[i])
            usedLetterCount[c-'a']--;
    }

    void updateMaxScore(vector<int>& score){
        int currScore = 0;
        for(int i = 0; i < 26; i++){
            if(usedLetterCount[i] > letterCount[i])
                return;

            currScore += score[i] * usedLetterCount[i];
        }

        if(currScore > maxScore)
            maxScore = currScore;
    }
};




/*
Runtime
76
ms
Beats
14.37%
of users with C++
Memory
31.66
MB
Beats
16.89%
of users with C++
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(char c : letters) 
            letterCount[c]++;

        vector<int> usedWordsIdx;
        backtrack(words, letters, score, usedWordsIdx, 0);

        return maxScore;
    }
private:
    int maxScore = 0;
    unordered_map<string, int> wordToScore;
    unordered_map<char, int> letterCount;
    void backtrack(vector<string>& words, vector<char>& letters, 
                   vector<int>& score, vector<int>& usedWordsIdx, int i)
    {
        if(i == words.size()){
            maxScore = max(maxScore, calcCurrScore(words, letters, score, usedWordsIdx));
            return;
        }

        // exclude
        backtrack(words, letters, score, usedWordsIdx, i+1);

        // include 
        usedWordsIdx.push_back(i);
        backtrack(words, letters, score, usedWordsIdx, i+1);
        usedWordsIdx.pop_back();

    }

    int calcCurrScore(vector<string>& words, vector<char>& letters, 
                     vector<int>& score, vector<int>& usedWordsIdx)
    {   
        int m = letters.size();
        vector<int> used(26, 0);
        int currScore = 0;
        for(int wordIdx : usedWordsIdx){
            string& word = words[wordIdx];
            int wordScore = 0;
            for(char c : word){
                
                if(used[c-'a'] >= letterCount[c])
                    return 0;

                wordScore += score[c-'a'];
                used[c-'a']++;
            }

            currScore += wordScore;
        }

        return currScore;
    }
};





/*
Runtime
85
ms
Beats
13.98%
of users with C++
Memory
11.63
MB
Beats
89.51%
of users with C++
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        
        int n = words.size();
        int end = (1 << n) - 1;
        int maxScore = INT_MIN;

        int m = letters.size();
        vector<bool> used(m, false);

        for(int i = 1; i <= end; i++){
            int mask = i;

            bool notFound = false;
            int currScore = 0;
            for(int i = 0; i < m; i++) 
                used[i] = false;

            for(int j = 0; j < n; j++){
                if(mask & 1){
                    
                    int wordScore = 0;
                    for(char c : words[j]){
                        
                        notFound = true;
                        for(int k = 0; k < m; k++){
                            if(c == letters[k]){
                                if(!used[k]){
                                    used[k] = true;
                                    wordScore += score[c-'a'];
                                    notFound = false;
                                    break;
                                }
                            }
                        }

                        if(notFound){
                            break;
                        }
                    }

                    if(notFound)
                        break;

                    currScore += wordScore;
                }else{
                    notFound = false;
                }

                if(notFound)
                    break;

                mask >>= 1;
            }

            if(notFound)
                continue;

            maxScore = max(maxScore, currScore);
        }

        if(maxScore < 0) 
            return 0;

        return maxScore;
    }
};


int main(){


    vector<string> words({"dog","cat","dad","good"});
    vector<char> letters({'a','a','c','d','d','d','g','o','o'});
    vector<int> score({1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0});

    Solution sol;
    int x = sol.maxScoreWords(words, letters, score);


    return 0;
}
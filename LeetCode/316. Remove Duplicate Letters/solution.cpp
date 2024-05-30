#include <string>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <vector>
using namespace std;




/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.95
MB
Beats
87.52%
of users with C++
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string stk = "";
        vector<bool> used(26, false);
        vector<int> letterCount(26, 0);

        for(char c : s) 
            letterCount[c-'a']++;


        for(char c : s){

            int charIdx = c-'a';
            
            if(used[charIdx]){
                letterCount[charIdx]--;
                continue;
            }

            while(!stk.empty() && c < stk.back() && letterCount[stk.back()-'a'] > 0){
                used[stk.back()-'a'] = false;
                stk.pop_back();
            }

            stk.push_back(c);
            letterCount[charIdx]--;
            used[charIdx] = true;
        }

        return stk;
    }
};





/*
Runtime
3
ms
Beats
49.33%
of users with C++
Memory
9.65
MB
Beats
19.12%
of users with C++
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> stk;
        vector<bool> used(26, false);

        unordered_map<char, int> letterCount;
        for(char c : s) 
            letterCount[c]++;

        for(char c : s){
            
            if(used[c-'a']){
                letterCount[c]--;
                continue;
            }

            while(!stk.empty() && c < stk.top() && letterCount[stk.top()] > 0){
                used[stk.top()-'a'] = false;
                stk.pop();
            }

            stk.push(c);
            letterCount[c]--;
            used[c-'a'] = true;            
        }

        string res = "";
        while(!stk.empty()){
            res += stk.top(); 
            stk.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
#include <vector>
#include <string>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.92
MB
Beats
83.80%
of users with C++
*/
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() > 0)
            backtrack(digits, 0);
        return ans;
    }

private:
    void backtrack(string& digits, int i){
        if(i == digits.size()){
            ans.push_back(path);
            return;
        }

        // try all chars for current digit
        int digit = digits[i]-'0';
        for(char c : mp[digit]){
            path.push_back(c);
            backtrack(digits, i+1);
            path.pop_back();
        }
    }

    vector<string> ans;
    string path = "";
    vector<string> mp = vector<string>({
        "",         // 0
        "",         // 1
        "abc",      // 2
        "def",      // 3
        "ghi", 
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"      // 9
    });
};
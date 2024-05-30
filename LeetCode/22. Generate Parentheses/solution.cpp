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
12.13
MB
Beats
78.07%
of users with C++
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        backtrack(n, 0, 0, 0);
        return allComb;
    }

private:
    void backtrack(int n, int idx, int leftCount, int rightCount){
        if(idx == n*2){
            allComb.push_back(path);
            return;
        }

        if(leftCount < n){
            path.push_back('(');
            backtrack(n, idx+1, leftCount+1, rightCount);
            path.pop_back();
        }
        
        if(leftCount > rightCount && rightCount < n){
            path.push_back(')');
            backtrack(n, idx+1, leftCount, rightCount+1);
            path.pop_back();
        }
    }

    vector<string> allComb;
    string path;
};
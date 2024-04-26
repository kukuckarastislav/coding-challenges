#include <vector>
#include <string>
#include <stack>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
15.29
MB
Beats
97.40%
of users with C++
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> stk;
        for(string& token : tokens){
            if("+" == token){
                int x = stk.top(); stk.pop();
                stk.top() += x;
            }else if("-" == token){
                int x = stk.top(); stk.pop();
                stk.top() -= x;
            }else if("*" == token){
                int x = stk.top(); stk.pop();
                stk.top() *= x;
            }else if("/" == token){
                int x = stk.top(); stk.pop();
                stk.top() /= x;
            }else{
                stk.push(stoi(token));
            }
        }

        if(!stk.empty())
            return stk.top(); 

        return 0;
    }
};
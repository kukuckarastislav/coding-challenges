#include <string>
#include <stack>
using namespace std;

/*
Runtime
3
ms
Beats
98.34%
of users with C++
Memory
9.22
MB
Beats
68.71%
of users with C++
*/

class Solution {
public:
    int calculate(string s) {
        
        stack<int> stk;
        int res = 0;
        int curr = 0;
        int sign = 1;
        int n = s.size();

        for(int i = 0; i < n; i++){
            char c = s[i];
            
            if(c >= '0' && c <= '9'){
                curr = curr*10 + (c-'0');
            }else if(c == '+'){
                res += curr*sign;
                curr = 0;
                sign = 1;
            }else if(c == '-'){
                res += curr*sign;
                curr = 0;
                sign = -1;
            }else if(c == '('){
                stk.push(res);
                stk.push(sign);
                res = 0;
                sign = 1;
            }else if(c == ')'){
                res += curr*sign;
                res *= stk.top(); stk.pop();
                res += stk.top(); stk.pop();
                curr = 0;
            }
        }
        res += curr*sign;

        return res;
    }
};


int main(){

    Solution sol;
    //string s = "(1+(4+5+2)-3)+(6+8)";
    string s = "2147483647";
    int r = sol.calculate(s);

    return 0;
}
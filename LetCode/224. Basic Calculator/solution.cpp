#include <string>
#include <stack>
using namespace std;



class Solution {
public:
    int calculate(string s) {
        
        stack<pair<int, char>> stk;

        int n = s.size();
        int operand = 0;
        int dec = 0;
        bool creatingOperand = false;

        for(int i = 0; i < n; i++){

            char c = s[i];
            if(c >= '0' && c <= '9'){
                operand += c-'0' * dec*10;
                dec++;
                creatingOperand = true;
                if(i < n-1)
                    continue;
            }

            if(creatingOperand){
                if(stk.size()==1 && stk.top().second == '-'){
                    stk.top().second = 0;
                    stk.top().first = -operand;
                }else if(stk.size() > 1 && stk.top().second == '-'){
                    stk.pop();
                }else{
                    stk.emplace(operand, 0);
                }
                operand = 0; dec = 0;
                creatingOperand = false;
            }

            // try to calculate???
            if(stk.size() >= 3){
                
            }

            if(c == ' ') 
                continue;

            if(c == '('){

            }
            
            stk.emplace(0, c); // + - ( )

            
        }

        return 0;
    }
};
#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty()){
                    return false;
                }
                char t = st.top();
                if(t == '(' && c == ')'){
                    st.pop();
                }else if(t == '{' && c == '}'){
                    st.pop();
                }else if(t == '[' && c == ']'){
                    st.pop();
                }else{
                    st.push(c);
                }
            }
        }

        return st.empty();
    }
};
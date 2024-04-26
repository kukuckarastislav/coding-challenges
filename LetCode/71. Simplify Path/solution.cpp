#include <string>
#include <sstream>
#include <stack>
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
9.93
MB
Beats
87.23%
of users with C++
*/
class Solution {
public:
    string simplifyPath(string path) {
        
        string token = "";
        stringstream ss(path);
        vector<string> stk;
        
        while(getline(ss, token, '/')){

            if(token == "" || token == ".")
                continue;

            if(token != "..")
                stk.push_back(token);
            else if(!stk.empty())
                stk.pop_back();
        }

        string res = "";
        for(string& s:stk){
            res += '/'+s;
        }

        if(res.size() == 0)
            res.push_back('/');

        return res;
    }
};




/*
Runtime
6
ms
Beats
45.45%
of users with C++
Memory
11.62
MB
Beats
28.78%
of users with C++
*/
class Solution {
public:
    string simplifyPath(string path) {
        
        string token = "";
        stringstream ss(path);
        stack<string> stk;
        
        while(getline(ss, token, '/')){

            if(token == "" || token == ".")
                continue;

            if(token != "..")
                stk.push(token);
            else if(!stk.empty())
                stk.pop();
        }

        string res = "";
        while(!stk.empty()){
            res = '/' + stk.top() + res;
            stk.pop();
        }

        if(res.size() == 0)
            res.push_back('/');

        return res;
    }
};







/*
Runtime
4
ms
Beats
73.15%
of users with C++
Memory
11.35
MB
Beats
57.58%
of users with C++
*/
class Solution {
public:
    string simplifyPath(string path) {
        
        string sb = "";
        stack<string> stk;
        int n = path.size();

        for(int i = 0; i < n+1; i++){
            if( (i == n || path[i] == '/') && sb.size() > 0){
                if(sb == ".." && !stk.empty()){
                    stk.pop();
                }else if(sb != ".." && sb != "."){
                    stk.push(sb);
                }

                sb = "";
            }else if(i < n && path[i] != '/'){
                sb += path[i];
            }
        }

        string res = "";
        while(!stk.empty()){
            res = '/' + stk.top() + res;
            stk.pop();
        }

        if(res.size() == 0)
            res.push_back('/');

        return res;
    }
};
/*
Runtime
3
ms
Beats
99.59%
of users with C++
Memory
9.58
MB
Beats
96.15%
of users with C++
*/
// with c++ built in string, (monotonic stack)
class Solution {
public:
    string removeKdigits(string num, int k) {
        if(k == 0)
            return num;
        int n = num.size();
        if(n == k) 
            return "0";
        
        string res = "";

        for(int i = 0; i < n; i++){
            while(res.size() && res.back() > num[i] && k){
                res.pop_back();
                k--;
            }

            if(res.empty() && num[i] == '0')
                continue;

            res.push_back(num[i]);
        }

        while(res.size() && k){
            res.pop_back();
            k--;
        }

        if(res.size() == 0)
            res += '0';

        return res;
    }

};


// with stack (monotonic stack)
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) 
            return "0";
        if(k == 0)
            return num;

        stack<char> m_stack;

        for(int i = 0; i < n; i++){
            while(!m_stack.empty() && m_stack.top() > num[i] && k > 0){
                m_stack.pop();
                k--;
            }

            if(m_stack.empty() && num[i] == '0')
                continue;

            m_stack.push(num[i]);
        }

        while (k > 0 && !m_stack.empty()) {
            m_stack.pop();
            k--;
        }

        string res = "";
        while(!m_stack.empty()){
            res += m_stack.top();
            m_stack.pop();
        }

        reverse(res.begin(), res.end());

        if(res.size() == 0) 
            res += '0';

        return res;
    }


};


// with loops, not fast engought
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n == k) 
            return "0";

        int an = n-k;
        string ans(an, '?');

        int prevJ = 0;
        for(int i = 0; i < an; i++){
            int j = prevJ;
            while(j < n-an+i+1){
                if(num[j] < ans[i]){
                    ans[i] = num[j];
                    prevJ = j;
                    prevJ++;
                }

                j++;
            }
        }

        int i = 0;
        while(i < an-1){
            if(ans[i] != '0') 
                break;
            i++;
        }
        if(i){
            ans.erase(0, i);
        }

        return ans;
    }


};
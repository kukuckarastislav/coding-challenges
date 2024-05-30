// time: O(n)
// memmory: O(1)
// Beats 100%, 0ms
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.16
MB
Beats
96.41%
of users with C++
*/
class Solution {
public:
    string reverseWords(string s) {

        // removing spaces
        auto itLeft = s.begin();
        auto itRight = itLeft;
        bool oneSpaceCanBeAdded = false;
        while(itRight != s.end()){
            if(*itRight != ' '){
                *itLeft = *itRight;
                itLeft++;
                oneSpaceCanBeAdded = true;
            }else if(oneSpaceCanBeAdded){
                *itLeft = ' ';
                itLeft++;
                oneSpaceCanBeAdded = false;
            }

            itRight++;
        }
        
        if(itLeft != s.end())
            s.erase(itLeft, s.end());
        
        while(s[s.size()-1] == ' ') s.pop_back();

        reverse(s.begin(), s.end());
        itLeft = s.begin();
        itRight = itLeft;
        while(itLeft != s.end()){
            
            while(itRight != s.end() && *itRight != ' '){
                itRight++;
            }

            if(itLeft != itRight){
                reverse(itLeft, itRight);
                itLeft = itRight;
                if(itLeft == s.end()) break;
            }

            itLeft++;
            itRight = itLeft;
        }
        
        return s;
    }
};




// time: O(n)
// memmory: O(n)
// Beats 100%, 0ms
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.46
MB
Beats
83.33%
of users with C++
*/
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res(n, ' ');
        int r = 0;

        int i = n-1;
        int j = 0;
        while(i >= 0){
            
            if(s[i] != ' '){
                j++;
                i--;
                continue;
            }

            if(j > 0){
                for(int k = i+1; k <= i+j; k++){
                    res[r++] = s[k];
                }
                r++;
                j = 0;
            }

            i--;
        }

        if(j > 0){
            for(int k = i+1; k <= i+j; k++){
                res[r++] = s[k];
            }
        }

        while(res[res.size()-1] == ' '){
            res.pop_back();
        }

        return res;
    }
};




// time: O(n)
// memmory: O(n)
// Beats 82.95%, 3ms
/*
Runtime
3
ms
Beats
82.95%
of users with C++
Memory
8.36
MB
Beats
87.39%
of users with C++
*/
class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        int n = s.size();

        int i = n-1;
        int j = 0;
        while(i >= 0){
            
            if(s[i] != ' '){
                j++;
                i--;
                continue;
            }

            if(j > 0){
                for(int k = i+1; k <= i+j; k++){
                    res += s[k];
                }
                res += ' ';
                j = 0;
            }

            i--;
        }

        if(j > 0){
            for(int k = i+1; k <= i+j; k++){
                res += s[k];
            }
        }else if(res.size() > 0)
            res.pop_back(); // for removing last ' ', better than use if a lot of time ...

        return res;
    }
};


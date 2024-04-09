#include <string>
/*
Runtime
3
ms
Beats
97.72%
of users with C++
Memory
9.88
MB
Beats
98.82%
of users with C++
*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) 
            return s;

        int n = s.size();
        string res(n, ' ');
        int k = 0;

        int inc = numRows-1 + numRows-1;
        for(int i = 0; i < n; i+=inc){
            res[k++] = s[i];
        }
        for(int row = 1; row < numRows-1; row++){
            int i = row;
            int j = row + inc - 2*row;
            while(j < n){

                res[k++] = s[i];
                res[k++] = s[j];

                i += inc;
                j += inc;
            }
            if(i < n){
                res[k++] = s[i];
            }
        }
        for(int i = numRows-1; i < n; i+=inc){
            res[k++] = s[i];
        }
        
        return res;
    }
};

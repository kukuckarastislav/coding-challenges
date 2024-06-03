#include <string>
using namespace std;


/*
Runtime
15
ms
Beats
87.56%
of users with C++
Memory
11.73
MB
Beats
97.58%
of users with C++
*/
class Solution {
public:
    int appendCharacters(string s, string t) {
        int ns = s.size(), nt = t.size();

        int i = 0, j = 0;

        while(i < ns && j < nt){
            if(s[i] == t[j]) j++;

            i++;
        }

        return nt-j;
    }
};
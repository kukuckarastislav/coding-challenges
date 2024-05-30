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
7.32
MB
Beats
91.39%
of users with C++
*/
class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n = word.size();
        int j;
        for(j = 0; j < n; j++){
            if(word[j] == ch){
                break;
            }
        }

        if(j == n) 
            return word;

        int i = 0;
        while(i < j){
            char c = word[i];
            word[i] = word[j];
            word[j] = c;

            i++;
            j--;
        }

        return word;
    }
};
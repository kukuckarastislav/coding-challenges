#include <cmath>
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
7.78
MB
Beats
78.98%
of users with C++
*/
class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int n = s.size();

        for(int i = 0; i < n-1; i++){
            score += abs(s[i] - s[i+1]);
        }
        
        return score;
    }
};
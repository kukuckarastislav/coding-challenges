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
7.39
MB
Beats
93.86%
of users with C++
*/
/*
    Time:  O(n)
    Space: O(1)
*/
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        if(n == 1) 
            return 0;

        int steps = n-1;
        for(int i = n-1; i > 0; i--){
            if(s[i] == '1'){
                steps++;
                s[i-1]++;
            }else if(s[i] == '2'){
                s[i-1]++;
            }
        }

        if(s[0] == '2') steps++;
        
        return steps;
    }
};







/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.46
MB
Beats
76.47%
of users with C++
*/
class Solution {
public:
    int numSteps(string s) {
        int n = s.size();

        if(n == 1) 
            return 0;

        int steps = n-1;
        for(int i = n-1; i > 0; i--){
            if(s[i] == '1'){
                steps++;
                bool overflow = addOne(s, i);
                if(overflow) steps++;
            }
        }
        
        return steps;
    }

    bool addOne(string& s, int idx){
        char firstBit = s[0];
        for(int i = idx; i >= 0; i--){
            s[i] += 1;
            if(s[i] == '1'){
                return false;
            }
            s[i] = '0';
        }

        s[0] = '0';
        return true;
    }
};
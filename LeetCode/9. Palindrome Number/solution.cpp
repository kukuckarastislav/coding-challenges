#include <cmath>

/*
Runtime
4
ms
Beats
84.49%
of users with C++
Memory
8.02
MB
Beats
96.43%
of users with C++
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        long p = 0;
        long cx = x;

        while(cx){
            p = p * 10 + cx % 10;
            cx /= 10;
        }

        return x == p;
    }
};

/*
Runtime
7
ms
Beats
71.80%
of users with C++
Memory
8.43
MB
Beats
29.38%
of users with C++
*/
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        int n = getNumLen(x);
        int i = 0;
        int j = n - 1;

        while(i < j && digitAt(x, i) == digitAt(x, j)){
            i++;
            j--;
        }

        return i >= j;
    }

    int digitAt(int x, int idx){
        return (int)(x / pow(10, idx)) % 10;
    }

    int getNumLen(int x){
        int n = 0;
        while(x){
            x /= 10;
            n++;
        }
        return n;
    }
};
#include <cmath>


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.08
MB
Beats
44.37%
of users with C++
*/
class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0)
            return 1;
        
        if(n < 0)
            x = 1 / x;
        
        n = abs(n);
        double pow = 1;
        
        while(n){ 
            if(n & 1) 
                pow *= x;
            
            x *= x;
            n >>= 1;
        }
        
        return pow;
    }
};


// TLE
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(x == 1 || n == 0)
            return 1;

        for(int i = 0; i < abs(n); i++){
            res *= x;
        }

        if(n < 0)
            res = 1/res;

        return res;
    }
};
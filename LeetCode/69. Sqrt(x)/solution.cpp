
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.44
MB
Beats
39.38%
of users with C++
*/
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x;
        long m = 0;

        while(l <= r){
            m = l + (r - l)/2;

            if(m*m > x)
                r = m - 1;
            else if(m*m < x)
                l = m + 1;
            else
                return m;
        }

        return r;
    }
};
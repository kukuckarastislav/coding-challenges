#include <stdlib.h>
using namespace std;

#define uint32_t unsigned int

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.04
MB
Beats
65.98%
of users with C++
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        if(n == 0)
            return 0;

        uint32_t res = 0;

        for(int i = 0; i < 31; i++){
            if(n & 1) 
                res += 1;

            n >>= 1;
            res <<= 1;
        }

        if(n & 1)
            res += 1;

        return res;
    }
};



// cool
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
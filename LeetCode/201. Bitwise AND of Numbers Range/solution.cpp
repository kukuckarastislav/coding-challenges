#include <stdlib.h>



/*
Runtime
4
ms
Beats
81.02%
of users with C++
Memory
8.73
MB
Beats
79.36%
of users with C++
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int andRes = 0;

        int bit = (1 << 30);
        while(bit && (left & bit) == (right & bit)){
            
            if(left & bit)
                andRes |= bit;

            bit >>= 1;
        }

        return andRes;
    }
};


/*
Runtime
4
ms
Beats
81.02%
of users with C++
Memory
8.91
MB
Beats
8.28%
of users with C++
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int count = 0;
        while(left != right){
            left >>= 1;
            right >>= 1;
            count++;
        }

        return left << count;
    }
};

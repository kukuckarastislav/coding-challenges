
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
7.22
MB
Beats
66.03%
of users with C++
*/
class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            count += n&1;
            n >>= 1;
        }

        return count;
    }
};



class Solution {
public:
    int hammingWeight(int n) {
        return (n == 0) ? 0 : (n&1) + hammingWeight(n >> 1);
    }
};
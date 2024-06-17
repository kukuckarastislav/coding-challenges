#include <cmath>


/*
Runtime 0ms Beats 100.00%
Memory 6.97MB Beats 91.95%
*/
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = (long)sqrt(c);

        while(a <= b){
            long res = a*a + b*b;

            if(c > res){
                a++;
            }else if(c < res){
                b--;
            }else{
                return true;
            }
        }

        return false;
    }
};
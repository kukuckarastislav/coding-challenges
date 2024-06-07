#include <unordered_map>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 5) 
            return 0;

        int zeros = 0;
        int i = 5;
        while(n/i){
            zeros += n/i;
            i *= 5;
        }

        return zeros;
    }
};
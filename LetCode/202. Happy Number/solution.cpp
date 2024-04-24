#include <unordered_set>
using namespace std;

/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.03
MB
Beats
24.99%
of users with C++
*/
class Solution {
public:
    bool isHappy(int n) {
        
        unordered_set<int> seen;
        seen.insert(n);
        
        while(true){
            n = fun(n);
            if(n == 1) return true;
            if(seen.count(n)) return false;
            seen.insert(n);
        }
    }

    int fun(int x){
        int sum = 0;
        while(x > 0){
            int digit = x % 10;
            x /= 10;

            sum += digit*digit;
        }
        return sum;
    }
};
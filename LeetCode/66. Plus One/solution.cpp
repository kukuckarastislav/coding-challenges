#include <vector>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.24
MB
Beats
54.31%
of users with C++
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        int i = n-1;
        digits[i]++;
        while(i >= 0 && digits[i] == 10){
            digits[i] = 0;
            if(i - 1 >= 0){
                digits[i-1]++;
            }else{
                digits.insert(digits.begin(), 1);
            }
            i--;
        }

        return digits;
    }
};
#include <string>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
8.09
MB
Beats
56.85%
of users with C++
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();

        if(n < m)
            return addBinary(b, a);

        int carry = 0;
        int i = n-1;
        int j = m-1;
        while(j >= 0){

            a[i] += b[j] + carry;

            if(a[i] == 96){
                a[i] = '0';
                carry = 0;
            }else if(a[i] == 97){
                a[i] = '1';
                carry = 0;
            }else if(a[i] == 98){
                a[i] = '0';
                carry = 1;
            }else if(a[i] == 99){
                a[i] = '1';
                carry = 1;
            }

            i--; 
            j--;
        }

        while(i >= 0 && carry){
            a[i] += carry;
            if(a[i] == '1'){
                carry = 0;
            }else if(a[i] == '2'){
                a[i] = '0';
            }

            i--;
        }

        if(carry)
            a = '1'+a;
        
        return a;
    }
};
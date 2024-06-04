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
7.79
MB
Beats
88.42%
of users with C++
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int charCount[123] = {0};

        for(char c : s)
            charCount[c]++;

        int evenChars = 0;
        int oddChar = 0;
        for(int c = 'A'; c <= 'z'; c++){
            if(charCount[c] % 2){
                oddChar = 1;
                evenChars += (charCount[c] - 1);
            }else{
                evenChars += charCount[c];
            }
        }

        return evenChars + oddChar;
    }
};



// same with bits manipulation
class Solution {
public:
    int longestPalindrome(string s) {
        int charCount[123] = {0};

        for(char c : s)
            charCount[c]++;

        int evenChars = 0;
        int oddChar = 0;
        for(int c = 'A'; c <= 'z'; c++){
            evenChars += (charCount[c] | 1) - 1;
            oddChar += charCount[c] & 1;
        }

        if(oddChar)
            evenChars++;
            
        return evenChars;
    }
};
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        int prevRomanChar = 5000;
        
        int i = 0;
        while(i < n){
            int current = romanCharToInt(s[i]);
            if(prevRomanChar < current) current -= prevRomanChar*2;
            prevRomanChar = current;
            result += current;

            i++;
        }

        return result;
    }

    int romanCharToInt(char c){
        switch(c){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return -1;
        }
        return -1;
    }
};
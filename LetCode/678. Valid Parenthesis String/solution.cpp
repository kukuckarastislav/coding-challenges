#include <string>
using namespace  std;



class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        
        int leftCount = 0;
        int rightCount = 0;
        int asteriskCount = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == '('){
                leftCount++;
            }else if(s[i] == ')' && leftCount > rightCount){
                rightCount++;
            }else if(s[i] == ')') {
                if(asteriskCount > 0){
                    asteriskCount--;
                }else{
                    return false;
                }
            }else {
                asteriskCount++;
            }

        }

        leftCount = 0;
        rightCount = 0;
        asteriskCount = 0;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ')'){
                rightCount++;
            }else if(s[i] == '(' && rightCount > leftCount){
                leftCount++;
            }else if(s[i] == '(') {
                if(asteriskCount > 0){
                    asteriskCount--;
                }else{
                    return false;
                }
            }else {
                asteriskCount++;
            }

        }

        return true;
    }
};


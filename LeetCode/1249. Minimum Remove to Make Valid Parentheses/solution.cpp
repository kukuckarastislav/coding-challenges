/*
Runtime
15
ms
Beats
92.60%
of users with C++
Memory
12.18
MB
Beats
79.54%
of users with C++
*/
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string validStr = "";
        int leftCount = 0;
        int rightCount = 0;
        int diff = 0;

        for(char c : s){
            if(c == '('){
                leftCount++;
                diff++;
            }else if(c == ')' && diff > 0){
                rightCount++;
                diff--;
            }
        }

        if(leftCount < rightCount){
            rightCount = leftCount;
        }else{
            leftCount = rightCount;
        }
        
        for(char c : s){
            if(c == '('){
                if(leftCount > 0){
                    validStr += '(';
                    leftCount--;
                }
            }else if(c == ')'){
                if(rightCount > 0 && rightCount > leftCount){
                    validStr += ')';
                    rightCount--;
                }
            }else{
                validStr += c;
            }
        }

        return validStr;
    }
};
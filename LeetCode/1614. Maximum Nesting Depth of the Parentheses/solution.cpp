class Solution {
public:
    int maxDepth(string s) {
        int currMaxDepth = 0;
        int currDepth = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(') currDepth++;
            else if(s[i] == ')') currDepth--;

            currMaxDepth = max(currMaxDepth, currDepth);
        }

        return currMaxDepth;
    }
};
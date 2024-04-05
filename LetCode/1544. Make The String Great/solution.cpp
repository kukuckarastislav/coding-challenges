class Solution {
public:
    string makeGood(string s) {
        int left = 0;
        int right = 1;
        bool lowDashs = false;

        while(right < s.size()){
            // 'a'-'A'==32 but 'A'-'a'==-32
            if(abs(s[left] - s[right]) == 32){
                s[left] = '_';
                s[right] = '_';
                lowDashs = true;
                while(left >= 0 && s[left] == '_'){
                    left--;
                }
                if(left == -1){
                    left = right;
                }
            }else{
                do{
                    left++;
                }while(left < right && s[left] == '_');
            }
            
            right++;
        }

        if(lowDashs){
            removeLowDashs(s);
        }
        
        return s;
    }

    void removeLowDashs(string &s){
        auto itLeft = s.begin();
        auto itRight = itLeft;
        while(itRight != s.end()){
            if(*itRight == '_'){
                itRight++;
            }else{
                *itLeft = *itRight;
                itLeft++;
                itRight++;
            }
        }
        
        if(itLeft != s.end())
            s.erase(itLeft, s.end());
    }
};
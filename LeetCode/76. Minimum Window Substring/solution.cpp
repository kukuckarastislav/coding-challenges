class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if(sn < tn) return "";

        int minLen = sn + 1;
        int startIndex = 0;

        vector<int> map(128, 0);
        for(char c:t) map[c]++;

        int count = tn;
        
        int i = 0;
        int j = 0;

        while(j < sn){
            if(map[s[j++]]-- > 0){
                count--;
            }

            while(count == 0){
                if(j - i < minLen){
                    startIndex = i;
                    minLen = j - i;
                }

                if(map[s[i++]]++ == 0){
                    count++;
                }
            }


        }

        if(minLen > sn) 
            return "";

        return s.substr(startIndex, minLen);
    }
};







class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if(sn < tn) return "";

        int need = tn;
        int curr = 0;

        unordered_map<char, int> dictNeed;
        for(char c:t) {
            dictNeed[c]++;
        }

        unordered_map<char, int> dictCurr;

        int minLen = sn + 1;
        int startIndex = 0;

        int i = 0;
        int j = 0;

        char lastChar = ' ';

        while(j < sn){
            
            if(dictNeed[s[j]] > 0 && dictCurr[s[j]] < dictNeed[s[j]]){
                curr++;
            }
            dictCurr[s[j]]++;

            while(curr == need){
                if(j-i+1 < minLen){
                    minLen = j-i+1;
                    startIndex = i;
                }

                int ii = i;
                i++;
                dictCurr[s[ii]]--;
                if(dictCurr[s[ii]] < dictNeed[s[ii]]){
                    curr--;
                    break;
                }
            }


            j++;
        }

        if(minLen > sn) 
            return "";

        return s.substr(startIndex, minLen);
    }
};








class Solution {
public:
    string minWindow(string s, string t) {
        int sn = s.size();
        int tn = t.size();

        if(sn < tn) return "";

        unordered_map<char, int> dictNeed;
        for(char c:t) dictNeed[c]++;

        unordered_map<char, int> dictCurr;

        int minLen = sn + 1;
        int minLenIndex = 0;

        int i = 0;
        int j = 0;

        char lastChar = ' ';

        while(j < sn){
            dictCurr[s[j]]++;

            bool ok = true;
            if(minLen > sn){
                for(char c:t){
                    if(dictCurr[c] < dictNeed[c]){
                        ok = false;
                        break;
                    }
                }
            }else if(dictCurr[lastChar] < dictNeed[lastChar]){
                ok = false;
            }

            if(ok){
                while(i <= j){
                    if(j-i+1 < minLen){
                        minLen = j-i+1;
                        minLenIndex = i;
                    }
                    dictCurr[s[i]]--;
                    if(dictCurr[s[i]] < dictNeed[s[i]]){
                        lastChar = s[i];
                        break;
                    }
                    i++;
                }
                i++;
            }

            j++;
        }

        if(minLen > sn) 
            return "";

        return s.substr(minLenIndex, minLen);
    }
};
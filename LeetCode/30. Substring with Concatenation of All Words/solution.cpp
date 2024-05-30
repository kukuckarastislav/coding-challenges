/*
Runtime
27
ms
Beats
87.80%
of users with C++
Memory
21.63
MB
Beats
85.12%
of users with C++
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = s.size();
        int w = words.size();
        int wn = words[0].size();
        
        vector<int> subs;

        if(n < wn || n < w*wn) 
            return subs;
        
        unordered_map<string, int> dict;
        for(string &w:words) dict[w]++;

        for(int k = 0; k < wn; k++){
            unordered_map<string, int> seen;
            int left = k;
            int currLen = 0;

            for(int i = left; i+wn<=n; i+=wn){
                string temp = s.substr(i, wn);
                if(dict.count(temp)){
                    seen[temp]++;
                    currLen++;
                    while(seen[temp] > dict[temp]){
                        string temp1 = s.substr(left, wn);
                        seen[temp1]--;
                        currLen--;
                        left += wn;
                    }
                }else{
                    seen.clear();
                    currLen = 0;
                    left = i + wn;
                }

                if(currLen == w){
                    subs.push_back(left);
                    seen[s.substr(left, wn)]--;
                    currLen--;
                    left += wn;
                }
            }
        }
        

        return subs;
    }
};
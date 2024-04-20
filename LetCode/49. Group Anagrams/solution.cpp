/*
Runtime
20
ms
Beats
92.74%
of users with C++
Memory
22.48
MB
Beats
94.40%
of users with C++
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, int> mp;
        vector<vector<string>> ans; 

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];

            sort(temp.begin(), temp.end());
            
            if (mp.find(temp) != mp.end()) {
                ans[mp[temp]].push_back(strs[i]);
            } else {
                mp[temp] = ans.size();
                ans.push_back({strs[i]});
                
            }
        }

        return ans;
    }
};







class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groupedAnagrams;
        unordered_map<string, vector<string>> mapAnagram;

        for(const string& s : strs){
            mapAnagram[getSignature(s)].push_back(s);
        }

        for(const auto& e : mapAnagram){
            groupedAnagrams.push_back(e.second);
        }
        
        return groupedAnagrams;
    }

    string getSignature(const string& s){
        vector<int> azArr(26, 0);
        for(char c : s){
            azArr[c - 97]++;
        }

        stringstream ss;
        for(int i = 0; i < 26; i++){
            if(azArr[i]){
                ss << (char)(97+i) << azArr[i];
            }
        }
        return ss.str();
    }
};










class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> groupedAnagrams;
        vector<vector<int>> azArrs(n, vector<int>(27,0));
        unordered_set<string> addedAnagrams;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < strs[i].size(); j++){
                azArrs[i][strs[i][j] - 'a']++;
            }
            int s = 0;
            for(int j = 0; j < 26; j++){
                s += azArrs[i][j];
            }
            azArrs[i][26] = s;
        }

        for(int i = 0; i < n; i++){
            
            if(addedAnagrams.count(strs[i]))
                continue;
            
            addedAnagrams.insert(strs[i]);
            vector<string> anagrams;
            anagrams.push_back(strs[i]);

            for(int j = i+1; j < n; j++){
                if(azArrs[i][26] != azArrs[j][26]){
                    continue;
                }else{
                    bool diff = false;
                    for(int k = 0; k < 26; k++){
                        if(azArrs[i][k] != azArrs[j][k]){
                            diff = true;
                            break;
                        }
                    }
                    // detected anagrams
                    if(!diff){
                        addedAnagrams.insert(strs[j]);
                        anagrams.push_back(strs[j]);
                    }
                }
            }

            groupedAnagrams.push_back(anagrams);
        }

        return groupedAnagrams;
    }
};
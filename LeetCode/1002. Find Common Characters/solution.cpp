#include <string>
#include <vector>
using namespace std;


/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
11.04
MB
Beats
82.02%
of users with C++
*/
class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        
        int charOcc[2][26] = {0};
        for(int i = 0; i < 26; i++)
            charOcc[0][i] = INT_MAX;


        for(const string& word : words){
            for(char c : word)
                charOcc[1][c-'a']++;

            for(int i = 0; i < 26; i++){
                charOcc[0][i] = min(charOcc[0][i], charOcc[1][i]);
                charOcc[1][i] = 0;
            }
        }


        vector<string> ans;
        for(char i = 0; i < 26; i++){
            for(int j = 0; j < charOcc[0][i]; j++){
                ans.push_back(string(1, 'a'+i));
            }
        }

        return ans;
    }
};



int main(){

    vector<string> words = {"bella","label","roller"};
    Solution sol;
    auto ans = sol.commonChars(words);

    return 0;
}



#include <string>
#include <vector>
#include <unordered_map>
using namespace std;




/*
Runtime
17
ms
Beats
65.54%
of users with C++
Memory
9.03
MB
Beats
80.18%
of users with C++
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        int mp[26][100] = {{0}};
        int cnt[26] = {0};
        int dp[2][100];

        for(int i = 0; i < 100; i++){
            dp[0][i] = 0;
            dp[1][i] = INT_MAX;
        }

        for(int i = 0; i < n; i++){
            mp[ring[i]-'a'][cnt[ring[i]-'a']++] = i;
        }
        
        for(int k = m-1; k >= 0; k--){
            for(int r = 0; r < n; r++){
                for(int l = 0; l < cnt[key[k]-'a']; l++){
                    int nextChar = mp[key[k]-'a'][l];
                    int m = 1 + getCost(r,nextChar,n) + dp[0][nextChar];
                    if(m < dp[1][r]) dp[1][r] = m;
                }
            }
            for(int x = 0; x < 100; x++){
                dp[0][x] = dp[1][x];
                dp[1][x] = INT_MAX;
            }
        }

        return dp[0][0];
    }

    int getCost(int curr, int target, int n){
        int diff; // = abs(curr-target);
        if(curr > target) diff = curr - target;
        else diff = target - curr;
        if(diff > n/2) diff = n-diff;
        return diff;
    }
};






/*
Runtime
26
ms
Beats
52.48%
of users with C++
Memory
14.44
MB
Beats
62.39%
of users with C++
*/
class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        int m = key.size();
        vector<int> dp(n, 0);

        vector<vector<int>> mp(26, vector<int>());
        for(int i = 0; i < n; i++){
            mp[ring[i]-'a'].push_back(i);
        }

        for(int k = m-1; k >= 0; k--){
            vector<int> nextDP(n, INT_MAX);
            for(int r = 0; r < n; r++){
                for(int nextChar : mp[key[k]-'a']){
                    nextDP[r] = min(nextDP[r], 1 + getCost(r,nextChar,n) + dp[nextChar]);
                }
            }
            dp = nextDP;
        }

        return dp[0];
    }

    int getCost(int curr, int target, int n){
        int diff; // = abs(curr-target);
        if(curr > target) diff = curr - target;
        else diff = target - curr;
        if(diff > n/2) diff = n-diff;
        return diff;
    }
};









int main(){

    Solution solution;
    string ring = "godding";
    string key = "godding";
    int m = solution.findRotateSteps(ring, key);

    return 0;
}

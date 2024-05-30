#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Runtime
25
ms
Beats
52.93%
of users with C++
Memory
15.35
MB
Beats
52.25%
of users with C++
*/


struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1,T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  
    }
};

class Solution {
public:
    unordered_map<pair<int, int>, int, pair_hash> memo;
    int findRotateSteps(string ring, string key) {
        
        int n = ring.size();
        vector<vector<int>> mp(26, vector<int>());

        for(int i = 0; i < n; i++){
            mp[ring[i]-'a'].push_back(i);
        }

        int minSteps = getMinSteps(mp, ring, key, 0, 0);
        return minSteps + key.size();
    }

    int getMinSteps(vector<vector<int>>& mp, 
                    string& ring, string& key,
                    int currRingIndex, int currKeyIndex)
    {
        if(currKeyIndex == key.size()){
            return 0;
        }

        if(memo.count({currRingIndex, currKeyIndex})){
            return memo[{currRingIndex, currKeyIndex}];
        }

        int minS = INT_MAX;
        char c = key[currKeyIndex];

        int rn = ring.size();
        for(int k : mp[c-'a']){
            int ms = getCost(currRingIndex, k, rn) +
                    getMinSteps(mp, ring, key, k, currKeyIndex+1);
            if(ms < minS){
                minS = ms;
            }
        }
        
        memo[{currRingIndex, currKeyIndex}] = minS;
        return minS;
    }

    int getCost(int curr, int target, int n){
        int diff = abs(curr-target);
        if(diff > n/2) diff = n-diff;
        return diff;
    }
};






// memo without key pair, but int (x+1)*1000+y  
// ((currRingIndex+1)*1000+currKeyIndex)
class Solution {
public:
    unordered_map<int, int> memo;
    int findRotateSteps(string ring, string key) {
        
        int n = ring.size();
        vector<vector<int>> mp(26, vector<int>());

        for(int i = 0; i < n; i++){
            mp[ring[i]-'a'].push_back(i);
        }

        int minSteps = getMinSteps(mp, ring, key, 0, 0);
        return minSteps + key.size();
    }

    int getMinSteps(vector<vector<int>>& mp, 
                    string& ring, string& key,
                    int currRingIndex, int currKeyIndex)
    {
        if(currKeyIndex == key.size()){
            return 0;
        }

        if(memo.count(((currRingIndex+1)*1000+currKeyIndex))){
            return memo[((currRingIndex+1)*1000+currKeyIndex)];
        }

        int minS = INT_MAX;
        char c = key[currKeyIndex];

        int rn = ring.size();
        for(int k : mp[c-'a']){
            int ms = getCost(currRingIndex, k, rn) +
                    getMinSteps(mp, ring, key, k, currKeyIndex+1);
            if(ms < minS){
                minS = ms;
            }
        }
        
        memo[((currRingIndex+1)*1000+currKeyIndex)] = minS;
        return minS;
    }

    int getCost(int curr, int target, int n){
        int diff = abs(curr-target);
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


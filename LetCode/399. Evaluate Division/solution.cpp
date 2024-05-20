#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;


class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        int n = values.size();
        unordered_map<string, vector<pair<string, double>>> mp;

        // populate map
        for(int i = 0; i < n; i++){
            string divident = equations[i][0];
            string divisor = equations[i][1];
            double res = values[i];
            mp[divident].push_back({divisor, res});
            mp[divisor].push_back({divident, 1.0/res});
        }

        
        int m = queries.size();
        vector<double> ans(m, -1.0);

        for(int i = 0; i < m; i++){
            if(mp.find(queries[i][0]) == mp.end() or mp.find(queries[i][1]) == mp.end())
                continue;

            if(queries[i][0] == queries[i][1]){
                ans[i] = 1;
                continue;
            }

            // find path from queries[i][0] to queries[i][1]
            ans[i] = pathFromDividentToDivisor(mp, queries[i][0], queries[i][1]);

        }

        return ans;     
    }

    double pathFromDividentToDivisor(unordered_map<string, vector<pair<string, double>>>& mp, 
                                    const string& divident, const string& divisor)
    {
        unordered_map<string, double> visited;
        queue<string> que;

        que.push(divident);
        visited.insert({divident, 1.0});

        while(!que.empty()){
            string currNode = que.front(); que.pop();

            if(currNode == divisor){
                return visited[currNode];
            }

            for(auto nextNode : mp[currNode]){
                if(!visited.count(nextNode.first)){
                    que.push(nextNode.first);
                    visited.insert({nextNode.first, nextNode.second * visited[currNode]});
                }
            }
        }

        return -1;
    }
};

int main(){

    vector<vector<string>> eq({{"a", "b"}, {"b", "c"}});
    vector<double> val({2.0, 3.0});
    vector<vector<string>> queries({{"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"}});

    Solution sol;
    sol.calcEquation(eq, val, queries);

    return 0;
}
#include <vector>
using namespace std;


/*
Runtime
186
ms
Beats
85.80%
of users with C++
Memory
95.96
MB
Beats
74.69%
of users with C++
*/
class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        ans = vector<int>(n, 0);
        count = vector<int>(n, 1);

        mp.resize(n, vector<int>());
        for(int i = 0; i < n-1; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            mp[v1].push_back(v2);
            mp[v2].push_back(v1);
        }

        dfs1(0, -1);
        dfs2(0, -1);

        return ans;
    }


private:
    vector<vector<int>> mp;
    vector<int> count;
    vector<int> ans;


    void dfs1(int node, int parent){
        int m = mp[node].size();
        for(int j = 0; j < m; j++){
            int child = mp[node][j];
            if(child != parent){
                dfs1(child, node);
                count[node] += count[child];
                ans[node] += ans[child] + count[child];
            }
        }
    }

    void dfs2(int node, int parent){
        int m = mp[node].size();
        for(int j = 0; j < m; j++){
            int child = mp[node][j];
            if(child != parent){
                ans[child] = ans[node] - count[child] + (count.size() - count[child]);
                dfs2(child, node);
            }
        }
    }
};


#include <iostream>
int main(){
    int n = 6;
    vector<vector<int>> edges = {{0,1},{0,2},{2,3},{2,4},{2,5}};
    Solution solution;
    vector<int> res = solution.sumOfDistancesInTree(n, edges);
    
    return 0;
}











// TLE
class Solution {
private:
    vector<vector<int>> mp;
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);

        mp.resize(n, vector<int>());
        for(int i = 0; i < n-1; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            mp[v1].push_back(v2);
            mp[v2].push_back(v1);
        }

        for(int i = 0; i < n; i++){
            ans[i] = sumOfDistances(i, 0, -1);
        }

        return ans;
    }

    int sumOfDistances(int i, int depth, int prev){
        int m = mp[i].size();
        int sum = 0;
        for(int j = 0; j < m; j++){
            if(mp[i][j] != prev){
                sum += sumOfDistances(mp[i][j], depth+1, i);
            }
        }
        return sum + depth;
    }

};




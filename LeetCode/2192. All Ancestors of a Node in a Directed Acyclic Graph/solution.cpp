#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


/*
Runtime 84ms Beats 97.69%
Memory 58.11MB Beats 99.12%
*/
class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer(n, vector<int>(0));

        vector<vector<int>> prevNodes(n, vector<int>(0));
        vector<vector<int>> nextNodes(n, vector<int>(0));
        for(const auto& edge : edges){
            nextNodes[edge[0]].push_back(edge[1]);
            prevNodes[edge[1]].push_back(edge[0]);
        }

        vector<bool> visitedNodes(n, false);
        queue<int> que;
        for(int i = 0; i < n; i++)
            if(prevNodes[i].empty())
                que.push(i);
            

        while(!que.empty()){
            int currNode = que.front(); que.pop();

            if(visitedNodes[currNode])
                continue;

            bool allPrevNodesVisited = true;

            for(int prev : prevNodes[currNode]){
                if(!visitedNodes[prev]){
                    allPrevNodesVisited = false;
                    break;
                }
            }

            if(!allPrevNodesVisited){
                que.push(currNode);
                continue;
            }
    
            visitedNodes[currNode] = true;
        
            for(int prev : prevNodes[currNode]){
                answer[currNode].push_back(prev);
                answer[currNode].insert(answer[currNode].end(), answer[prev].begin(), answer[prev].end());
            }
            removeDuplicates(answer[currNode]);

            for(int next : nextNodes[currNode])
                que.push(next);
        }

        return answer;
    }

private:
    void removeDuplicates(vector<int>& nums){
        sort(nums.begin(), nums.end());
        auto it = unique(nums.begin(), nums.end());
        nums.erase(it, nums.end());
    }
};






int main(){

    int n = 8;
    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    Solution sol;
    auto ans = sol.getAncestors(n, edges);

    return 0;
}
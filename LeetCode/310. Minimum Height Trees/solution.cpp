#include <vector>
#include <queue>
using namespace std;


// BFS remove leaves
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<vector<int>> grid(n, vector<int>());
        vector<int> edgeCount(n, 0);
        for(int i = 0; i < n-1; i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            grid[v1].push_back(v2);
            grid[v2].push_back(v1);
            edgeCount[v1]++;
            edgeCount[v2]++;
        }

        queue<int> leavesQue;
        for(int i = 0; i < n; i++){
            if(edgeCount[i] == 1){
                leavesQue.push(i);
            }
        }

        while(leavesQue.size()){
            if(n == 2){
                int t = leavesQue.front(); 
                leavesQue.pop();
                return {t, leavesQue.front()};
            }else if(n <= 1){
                return {leavesQue.front()};
            }

            int leavesCount = leavesQue.size();
            for(int i = 0; i < leavesCount; i++){
                int node = leavesQue.front();
                leavesQue.pop();
                n--;

                for(int nei : grid[node]){
                    edgeCount[nei]--;
                    if(edgeCount[nei] == 1)
                        leavesQue.push(nei);
                }
            }
            
        }

        return {0};
    }
};





// with DFS, find longest Path (supremum) and return 1 or 2 central nodes
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        vector<vector<int>> grid(n, vector<int>());
        makeGrid(grid, edges);

        auto [d1, farthestNode] = findfarthestNodeFromCurrNode(grid, -1, 0, 1);
        auto [d2, longestPath] = findLongestPathInTreeDFS(grid, -1, farthestNode, 1);

        vector<int> res;
        if(d2 % 2 == 0){
            int i = d2 / 2;
            res.push_back(longestPath[i-1]);
            res.push_back(longestPath[i]);
        }else{
            res.push_back(longestPath[d2/2]);
        }

        return res;
    }

    void makeGrid(vector<vector<int>>& grid, vector<vector<int>>& edges){
        for(int i = 0; i < edges.size(); i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];

            grid[v1].push_back(v2);
            grid[v2].push_back(v1);
        }
    }

    pair<int, int> findfarthestNodeFromCurrNode(vector<vector<int>>& grid, int prev, int curr, int depth){
        int maxDepth = depth;
        int farthestNode = curr; 
        for(int next : grid[curr]){
            if(next != prev){
                auto [possibleDepth, node] = findfarthestNodeFromCurrNode(grid, curr, next, depth+1);
                if(possibleDepth > maxDepth){
                    maxDepth = possibleDepth;
                    farthestNode = node;
                }
            }
        }
        return {maxDepth, farthestNode};
    }

    pair<int, vector<int>> findLongestPathInTreeDFS(vector<vector<int>>& grid, int prev, int curr, int depth){
        int maxDepth = depth;
        vector<int> maxPath;
        for(int next : grid[curr]){
            if(next != prev){
                auto [possibleDepth, possiblePath] = findLongestPathInTreeDFS(grid, curr, next, depth+1);
                if(possibleDepth > maxDepth){
                    maxDepth = possibleDepth;
                    maxPath = possiblePath;
                }   
            }
        }
        maxPath.push_back(curr);
        return {maxDepth, maxPath};
    }
};
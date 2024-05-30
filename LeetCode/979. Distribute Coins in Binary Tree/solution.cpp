#include <cmath>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Runtime
3
ms
Beats
80.65%
of users with C++
Memory
15.44
MB
Beats
89.65%
of users with C++
*/
class Solution {
public:
    int minMoves = 0;

    int distributeCoins(TreeNode* root) {
        askChild(root);
        return minMoves;
    }

    int askChild(TreeNode* root){
        if(!root) return 0;

        int leftNeed = askChild(root->left);
        int rightNeed = askChild(root->right);

        int currCoins = root->val + leftNeed + rightNeed;
        if(currCoins == 1){
            return 0;
        }else if(currCoins > 1){
            minMoves += currCoins-1;
            return currCoins-1;
        }else{
            minMoves += abs(currCoins)+1;
            return currCoins-1;
        }

    }
};








class Solution {
public:
    int minMoves = 0;

    int distributeCoins(TreeNode* root) {
        askChild(root);
        return minMoves;
    }

    int askChild(TreeNode* root){
        if(!root) return 0;

        int leftNeed = askChild(root->left);
        int rightNeed = askChild(root->right);

        int currCoins = root->val + leftNeed + rightNeed - 1;
        minMoves += abs(currCoins);
        return currCoins;
    }
};











//////////////////////////////////////////////////////////////////// My first approach which did not give a minimal solution

#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
public:
    int distributeCoins(TreeNode* root) {
        
        vector<pair<TreeNode*, pair<int, int>>> lessCoinsNodes;
        vector<pair<TreeNode*, pair<int, int>>> moreCoinsNodes;
        queue<TreeNode*> que;

        que.push(root);
        int i = 0;
        
        while(!que.empty()){
            int qsize = que.size();

            bool noMoreLeafs = true;
            for(int j = 0; j < qsize; j++){
                TreeNode* node = que.front(); que.pop();

                if(!node){
                    que.push(nullptr);
                    que.push(nullptr);
                    continue;
                }

                if(node->val > 1)
                    moreCoinsNodes.push_back({node, {i, j}});
                else if(node->val < 1)
                    lessCoinsNodes.push_back({node, {i, j}});

                que.push(node->left);
                que.push(node->right);
                noMoreLeafs = false;
            }

            if(noMoreLeafs)
                break;

            i++;
        }

        printVec(lessCoinsNodes);
        cout << endl;
        printVec(moreCoinsNodes);

        return _distributeCoins(lessCoinsNodes, moreCoinsNodes);
    }

private:
    int _distributeCoins(vector<pair<TreeNode*, pair<int, int>>>& lessCoinsNodes, 
                         vector<pair<TreeNode*, pair<int, int>>>& moreCoinsNodes)
    {
        int moves = 0;
        int n = lessCoinsNodes.size();
        for(int i = 0; i < n; i++){
            int r1 = lessCoinsNodes[i].second.first;
            int c1 = lessCoinsNodes[i].second.second;
            
            auto [nearestNode, dist] = findIndexOfNearestNode(r1, c1, moreCoinsNodes);
            nearestNode->first->val--;
            if(nearestNode->first->val == 1)
                moreCoinsNodes.erase(nearestNode);
            
            moves += dist;
        }

        return moves;
    }

    pair<vector<pair<TreeNode *, pair<int, int>>>::iterator, int> 
    findIndexOfNearestNode(int r1, int c1, vector<pair<TreeNode*, pair<int, int>>>& moreCoinsNodes){
        int n = moreCoinsNodes.size();
        int minDistance = INT_MAX;
        vector<pair<TreeNode *, pair<int, int>>>::iterator itNearest;
        for(auto it = moreCoinsNodes.begin(); it != moreCoinsNodes.end(); it++){
            int r2 = it->second.first;
            int c2 = it->second.second;
            int dist = getDistance(r1, c1, r2, c2);
            if(dist < minDistance){
                minDistance = dist;
                itNearest = it;
            }
        }

        return {itNearest, minDistance};
    }

    int getPosition(int depth, int shift) {
        return (1 << depth) + shift;
    }

    // Function to convert a position to a binary string
    string getBinaryString(int position) {
        string binary = "";
        while (position > 0) {
            binary = (position % 2 == 0 ? '0' : '1') + binary;
            position /= 2;
        }
        return binary;
    }

    // Function to calculate the distance between two nodes
    int getDistance(int r1, int c1, int r2, int c2) {
        int pos1 = getPosition(r1, c1);
        int pos2 = getPosition(r2, c2);
        
        string bin1 = getBinaryString(pos1);
        string bin2 = getBinaryString(pos2);
        
        // Find the length of the common prefix
        int lca_depth = 0;
        int minLength = min(bin1.length(), bin2.length());
        for (int i = 0; i < minLength; ++i) {
            if (bin1[i] == bin2[i]) {
                lca_depth++;
            } else {
                break;
            }
        }
        
        lca_depth--;  // As depth is zero-based
        
        // Distance is the sum of the distances from the nodes to the LCA
        int distance = (r1 - lca_depth) + (r2 - lca_depth);
        return distance;
    }


    void printVec(vector<pair<TreeNode*, pair<int, int>>>& v){
        for(auto p : v){
            cout << "val:" << p.first->val << " pos:" << p.second.first  << "," << p.second.second << endl; 
        }
    }
};

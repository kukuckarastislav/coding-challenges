#include <vector>
#include <queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// BFS
/*
Runtime
3
ms
Beats
57.96%
of users with C++
Memory
14.22
MB
Beats
27.20%
of users with C++
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {

        if(!root) return {};
        
        vector<int> ans;
        int maxDepth = 0;
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});

        while(!que.empty()){
            auto curr = que.front(); que.pop();

            if(curr.second > maxDepth){
                ans.push_back(curr.first->val);
                maxDepth = curr.second;
            }

            if(curr.first->right)
                que.push({curr.first->right, curr.second+1});
                
            if(curr.first->left)
                que.push({curr.first->left, curr.second+1});
            
        }

        return ans;
    }
};






// DFS
/*
Runtime
2
ms
Beats
61.27%
of users with C++
Memory
13.78
MB
Beats
98.04%
of users with C++
*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }

private:
    int maxDepth = 0;
    vector<int> ans;

    void dfs(TreeNode* root, int depth){
        if(!root) return;

        depth++;

        if(depth > maxDepth){
            ans.push_back(root->val);
            maxDepth = depth;
        }

        if(root->right)
            dfs(root->right, depth);
        
        if(root->left)
            dfs(root->left, depth);
    }
};
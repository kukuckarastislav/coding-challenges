#include <stdlib.h>
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
4
ms
Beats
97.87%
of users with C++
Memory
23.53
MB
Beats
94.40%
of users with C++
*/
class Solution {
public:
    int minDiff = INT_MAX;
    TreeNode* prev = nullptr;

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minDiff;
    }

    void dfs(TreeNode* root){

        if(root->left) dfs(root->left);
        
        if(prev)
            minDiff = min(minDiff, root->val - prev->val);
        prev = root;

        if(root->right) dfs(root->right);
    }

};





/*
Runtime
7
ms
Beats
94.35%
of users with C++
Memory
23.62
MB
Beats
78.42%
of users with C++
*/
class Solution {
public:
    int minDiff = INT_MAX;
    int prev = -100001;

    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        return minDiff;
    }

    void dfs(TreeNode* root){
        if(root->left) dfs(root->left);
        
        minDiff = min(minDiff, root->val - prev);
        prev = root->val;

        if(root->right) dfs(root->right);
    }
};

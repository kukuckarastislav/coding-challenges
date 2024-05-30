/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*
Runtime
7
ms
Beats
95.21%
of users with C++
Memory
24.04
MB
Beats
99.74%
of users with C++
*/
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val, root, nullptr);
            return newNode;
        }else{
            _addOneRow(root, val, depth, 1);
            return root;
        }
    }

    void _addOneRow(TreeNode* root, int val, int targetDepth, int currDepth){
        if(!root) return;
        
        if(currDepth < targetDepth-1){
            _addOneRow(root->left, val, targetDepth, currDepth+1);
            _addOneRow(root->right, val, targetDepth, currDepth+1);
            return;
        }

        TreeNode* newNodeLeft = new TreeNode(val, root->left, nullptr);
        root->left = newNodeLeft;

        TreeNode* newNodeRight = new TreeNode(val, nullptr, root->right);
        root->right = newNodeRight; 

        return;
    }
};
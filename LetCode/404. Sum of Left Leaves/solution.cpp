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
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftSum = 0;
        int rightSum = 0;
        
        if(root->left != nullptr){
            if(root->left->left == nullptr && root->left->right == nullptr){
                leftSum += root->left->val;
            }
            leftSum += sumOfLeftLeaves(root->left);
        }

        if(root->right != nullptr){
            rightSum += sumOfLeftLeaves(root->right);
        }

        return leftSum + rightSum;
    }

};
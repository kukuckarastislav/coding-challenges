/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
10.88
MB
Beats
80.41%
of users with C++
*/

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
    int sumNumbers(TreeNode* root) {
        return dfsSumNumbers(root, 0);
    }

    int dfsSumNumbers(TreeNode* root, int curr){
        int newCurr = curr*10+root->val;
        
        if(root->left == nullptr && root->right == nullptr){
            return newCurr;
        }

        int sum = 0;
        if(root->left != nullptr){
            sum += dfsSumNumbers(root->left, newCurr);
        }

        if(root->right != nullptr){
            sum += dfsSumNumbers(root->right, newCurr);
        }

        return sum;
    }
};
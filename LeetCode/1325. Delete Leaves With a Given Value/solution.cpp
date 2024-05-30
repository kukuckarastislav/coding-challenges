
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
7
ms
Beats
92.90%
of users with C++
Memory
21.75
MB
Beats
9.62%
of users with C++
*/
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(removeLeafNode(root, target))
            return nullptr;
        
        return root;
    }

private:
    bool removeLeafNode(TreeNode* root, int target){

        if(root->left){
            if(removeLeafNode(root->left, target)){
                delete root->left;
                root->left = nullptr;
            }
        }

        if(root->right){
            if(removeLeafNode(root->right, target)){
                delete root->right;
                root->right = nullptr;
            }
        }

        if(!root->left && !root->right && root->val == target){
            return true;
        }

        return false;
    }
};

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
0
ms
Beats
100.00%
of users with C++
Memory
15.71
MB
Beats
28.38%
of users with C++
*/
class Solution {
public:
    void flatten(TreeNode* root) {
        dfs(root);
    }

    TreeNode* dfs(TreeNode* root){
        if(!root) return nullptr;

        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);

        if(leftTail){
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        if(rightTail) return rightTail;
        if(leftTail) return leftTail;
        return root;
    }
};
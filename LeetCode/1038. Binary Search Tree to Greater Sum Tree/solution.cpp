

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


/*
Runtime 0ms Beats 100.00%
Memory 10.04MB Beats 77.24%
*/
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        return root;
    }

private:
    int sum = 0;

    void dfs(TreeNode* root){

        if(!root)
            return;

        dfs(root->right);
        root->val += sum;
        sum = root->val;
        dfs(root->left);
    }
};
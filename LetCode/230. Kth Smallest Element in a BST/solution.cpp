
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
94.61%
of users with C++
Memory
22.42
MB
Beats
85.71%
of users with C++
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return kthVal;
    }

    int kth = 0;
    int kthVal = 0;

    void dfs(TreeNode* root, int k){
        if(root->left) dfs(root->left, k);
        
        if(kth < k){
            kth++;
            kthVal = root->val;
        }
        else return;

        if(root->right) dfs(root->right, k);
    }
};
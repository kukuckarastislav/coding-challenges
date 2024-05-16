
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
97.31%
of users with C++
Memory
17.37
MB
Beats
64.84%
of users with C++
*/

#define FALSE   0
#define TRUE    1
#define OR      2
#define AND     3

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }

        bool leftBool = evaluateTree(root->left);

        if(root->val == OR)
            return leftBool or evaluateTree(root->right);  // ||
        else
            return leftBool and evaluateTree(root->right); // &&
    }
};
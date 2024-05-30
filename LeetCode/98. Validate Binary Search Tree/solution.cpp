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
0
ms
Beats
100.00%
of users with C++
Memory
20.23
MB
Beats
28.25%
of users with C++
*/
class Solution {
public:
    long long currMax = -__INT64_MAX__;

    bool isValidBST(TreeNode* root) {
        if(root->left and !isValidBST(root->left)) 
            return false;

        if(root->val > currMax) currMax = root->val;
        else return false;

        if(root->right and !isValidBST(root->right)) 
            return false;

        return true;
    }
};




/*
Runtime
3
ms
Beats
97.90%
of users with C++
Memory
20.19
MB
Beats
60.74%
of users with C++
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, LONG_MIN, LONG_MAX);
    }

    bool _isValidBST(TreeNode* root, long leftlimit, long rightLimit) {
        if(!root) return true;
        
        if(root->val <= leftlimit or root->val >= rightLimit) 
            return false;
        
        return _isValidBST(root->left, leftlimit, root->val) and _isValidBST(root->right, root->val, rightLimit);
    }
};
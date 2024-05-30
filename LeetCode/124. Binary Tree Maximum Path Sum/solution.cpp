#include <vector>
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
19
ms
Beats
56.51%
of users with C++
Memory
26.00
MB
Beats
95.51%
of users with C++
*/

#define MIN -1001

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
private:
    int maxSum = MIN;
    
    int dfs(TreeNode* root){

        if(!root) return 0;
        
        if(!root->left && !root->right){
            maxSum = max(maxSum, root->val);
            return root->val;
        }

        int leftSum = max(0, dfs(root->left));
        int rightSum = max(0, dfs(root->right));

        maxSum = max(maxSum, root->val + leftSum + rightSum);

        return root->val + max(leftSum, rightSum);
    }
};
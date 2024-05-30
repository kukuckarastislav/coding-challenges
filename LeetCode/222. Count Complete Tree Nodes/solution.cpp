#include <vector>
#include <math>
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
87.43%
of users with C++
Memory
28.94
MB
Beats
96.82%
of users with C++
*/
class Solution {
public:

    int countNodes(TreeNode* root) {
        if(!root) return 0;
        return count(root);
    }

    int count(TreeNode* root){
        if(!root) 
            return 0;
        if(!root->left && !root->left)
            return 1;

        int leftCount = countByLeft(root, 0);
        int rightCount = countByRight(root, 0);

        if(leftCount == rightCount){
            return pow(2, leftCount) - 1;
        }
    
        return 1 + count(root->left) + count(root->right);
    }

    int countByLeft(TreeNode* root, int depth){
        if(!root) return depth;
        return countByLeft(root->left, depth+1);
    }

    int countByRight(TreeNode* root, int depth){
        if(!root) return depth;
        return countByRight(root->right, depth+1);
    }
};

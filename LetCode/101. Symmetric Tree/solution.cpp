#include <queue>
#include <stack>
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
17.62
MB
Beats
6.36%
of users with C++
*/
class Solution {
public:
    // iteratively
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> que;

        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();

            if(!leftNode && !rightNode) continue;
            if(!leftNode || !rightNode) return false;
            
            if(leftNode->val != rightNode->val) return false;

            que.push(leftNode->left);
            que.push(rightNode->right);

            que.push(leftNode->right);
            que.push(rightNode->left);
        }

        return true;
    }
};





/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
17.24
MB
Beats
71.89%
of users with C++
*/
class Solution {
public:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;

        return (left->val == right->val) && 
            isMirror(left->left, right->right) && 
            isMirror(left->right, right->left);
    }

    // recursively 
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }
};




/*
Runtime
3
ms
Beats
70.11%
of users with C++
Memory
17.29
MB
Beats
71.89%
of users with C++
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSameTree(root->left, invertTree(root->right));
    }

    // LetCode: 100. Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true;
        if(!p || !q) return false;
        if(p->val != q->val) return false;

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    // LetCode: 226. Invert Binary Tree
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};






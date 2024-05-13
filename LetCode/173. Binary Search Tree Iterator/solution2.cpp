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
19
ms
Beats
74.96%
of users with C++
Memory
27.75
MB
Beats
72.38%
of users with C++
*/
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        partialInorder(root);
    }
    
    int next() {
        TreeNode* top = stk.top(); stk.pop();
        partialInorder(top->right);
        return top->val;
    }
    
    bool hasNext() {
        return !stk.empty();
    }
    
private:
    stack<TreeNode*> stk;

    void partialInorder(TreeNode* root){
        while(root){
            stk.push(root);
            root = root->left;
        }
    }
};

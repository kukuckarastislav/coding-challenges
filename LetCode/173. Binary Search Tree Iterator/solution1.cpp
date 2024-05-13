
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/*
Runtime
19
ms
Beats
74.96%
of users with C++
Memory
28.09
MB
Beats
15.78%
of users with C++
*/
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        init(root);
        it = head;
    }
    
    int next() {
        int v = -1;
        if(it){
            v = it->val;
            it = it->next;
        }
        return v;
    }
    
    bool hasNext() {
        return it != nullptr;
    }
    
private:
    ListNode* head = nullptr;
    ListNode* it = nullptr;
    
    void init(TreeNode* root){
        if(!root) return;

        if(root->left)
            init(root->left);
        
        if(!head){
            head = new ListNode(root->val);
            it = head;
        }else{
            it->next = new ListNode(root->val);
            it = it->next;
        }

        if(root->right)
            init(root->right);

        return;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */



#include <vector>
#include <unordered_map>
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
3
ms
Beats
99.09%
of users with C++
Memory
26.01
MB
Beats
52.64%
of users with C++
*/
class Solution {
    int pi = 0;
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        pi = n-1;
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++){
            mp[inorder[i]] = i;
        }

        return helper(postorder, mp, 0, n-1);
    }

    TreeNode* helper(vector<int>& postorder, unordered_map<int, int>& mp, int start, int end){
        if(start > end) 
            return nullptr;

        TreeNode* root = new TreeNode(postorder[pi--]);

        int idx = mp[root->val];
        root->right = helper(postorder, mp, idx+1, end);
        root->left = helper(postorder, mp, start, idx-1);

        return root;
    }
};
#include <vector>
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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        vector<int> mp(6000, 0);
        for(int i = 0; i < n; i++){
            mp[inorder[i]+3000] = i;
        }

        int index = 0;

        return constructTree(preorder, mp, 0, n-1, index);
    }

    TreeNode* constructTree(vector<int>& preorder, vector<int>& mp, int start, int end, int& index){
        if(start > end) return nullptr;
        
        int rootVal = preorder[index];
        int indexInInorder = mp[rootVal+3000];
        index++;

        TreeNode* root = new TreeNode(rootVal);
        root->left = constructTree(preorder, mp, start, indexInInorder-1, index);
        root->right = constructTree(preorder, mp, indexInInorder+1, end, index);

        return root;
    }
};

/*
3,9,8,4,20,15,2,12,11,7,5,6
8,9,4,3,12,2,15,11,20,5,7,6

3,9,20,8,4,15,7,null,null,null,null,2,11,5,6,12
*/

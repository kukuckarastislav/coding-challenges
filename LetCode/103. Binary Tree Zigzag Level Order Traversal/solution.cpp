#include <vector>
#include <queue>
#include <algorithm>
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
13.12
MB
Beats
28.83%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> que;
        que.push(root);
        bool leftToRight = false;
        
        while(!que.empty()){
            int size = que.size();

            vector<int> v;
            while(size--){
                TreeNode* node = que.front(); que.pop();
                v.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }

            if(leftToRight)
                reverse(v.begin(), v.end());

            ans.push_back(v);
            leftToRight = !leftToRight;
        }

        return ans;
    }
};
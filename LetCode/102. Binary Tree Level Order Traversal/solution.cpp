#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
// BFS
/*
Runtime
0
ms
Beats
100.00%
of users with C++
Memory
14.92
MB
Beats
38.68%
of users with C++
*/
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();

            vector<int> v;
            while(size--){
                TreeNode* node = que.front(); que.pop();
                v.push_back(node->val);

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            ans.push_back(v);
        }
        
        return ans;
    }
};
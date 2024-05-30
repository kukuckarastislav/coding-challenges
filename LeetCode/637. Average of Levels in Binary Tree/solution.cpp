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

// Tree BFS
/*
Runtime
8
ms
Beats
80.58%
of users with C++
Memory
22.26
MB
Beats
71.07%
of users with C++
*/
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> que;
        vector<double> ans;
        que.push(root);

        while(!que.empty()){
            int qsize = que.size();

            double sum = 0;
            int count = qsize;
            while(qsize--){
                TreeNode* node = que.front(); que.pop();

                sum += node->val;
                if(node->left)
                    que.push(node->left);

                if(node->right)
                    que.push(node->right);
            }

            ans.push_back(sum/count);
        }

        return ans;
    }
};
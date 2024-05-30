#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


/*
Runtime
11
ms
Beats
72.99%
of users with C++
Memory
19.26
MB
Beats
9.68%
of users with C++
*/
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> p_path;
        vector<TreeNode*> q_path;

        findPath(root, p, p_path);
        findPath(root, q, q_path);

        return LCA(p_path, q_path);
    }

    TreeNode* LCA(vector<TreeNode*>& p_path, vector<TreeNode*>& q_path){
        TreeNode* ancestor = nullptr;
        int i = p_path.size()-1;
        int j = q_path.size()-1;
        while(i >= 0 && j >=0){
            if(p_path[i]->val == q_path[j]->val)
                ancestor = p_path[i];
            else
                break;
            
            i--;
            j--;
        }
        return ancestor;
    }

    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path){
        if(!root) return false;

        if(root->val == node->val){
            path.push_back(root);
            return true;
        }

        if(findPath(root->left, node, path)){
            path.push_back(root);
            return true;
        }
        
        if(findPath(root->right, node, path)){
            path.push_back(root);
            return true;
        }

        return false;
    }

    void printPath(vector<TreeNode*>& path){
        int n = path.size();
        for(int i = 0; i < n; i++){
            cout << path[i]->val << " ";
        }
        cout << endl;
    }
};
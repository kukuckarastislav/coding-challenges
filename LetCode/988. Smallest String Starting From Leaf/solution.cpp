class Solution {
public:
    string smallestFromLeaf(TreeNode* root) {
        string res;
        dfs(root, "", res);
        return res;
    }
    
    void dfs(TreeNode* node, string path, string& res) {
        if (node == nullptr) return;
        
        path += char(97 + node->val);

        if (node->left == nullptr && node->right == nullptr) {
            reverse(path.begin(), path.end());

            if (res.empty() || path < res) {
                res = path;
            }

            reverse(path.begin(), path.end());
        }
        
        dfs(node->left, path, res);
        dfs(node->right, path, res);
    }
};
#include <vector>
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
5
ms
Beats
82.20%
of users with C++
Memory
20.74
MB
Beats
52.67%
of users with C++
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return _sortedArrayToBST(nums, 0, nums.size());
    }

    TreeNode* _sortedArrayToBST(vector<int>& nums, int start, int end){
        if(start == end)
            return nullptr;

        int mid = (start + (end-1)) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums, start, mid);
        root->right = _sortedArrayToBST(nums, mid+1, end);
        return root;
    }
};
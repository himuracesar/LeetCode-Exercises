/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        
        TreeNode* root = nullptr;
        root = CreateTree(root, start, end, nums);
        
        return root;
    }
    
    TreeNode* CreateTree(TreeNode* root, int start, int end, vector<int>& nums)
    {
        if(start > end)
            return nullptr;
        
        int mid = (start + end) / 2;
        
        root = new TreeNode(nums[mid]);
        root->left = CreateTree(root->left, start, mid - 1, nums);
        root->right = CreateTree(root->right, mid + 1, end, nums);
        
        return root;
    }
};
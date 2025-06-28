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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root->left, (long)INT_MIN - 1, root->val) && isValidBST(root->right, root->val, (long)INT_MAX + 1);
    }

    bool isValidBST(TreeNode* root, long min, long max){
        if(root == nullptr)
            return true;
    
        if(root->val <= min || root->val >= max)
            return false;

        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};
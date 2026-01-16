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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> memo;

        BSTtoArray(root, memo);

        return memo[k-1];
    }

    void BSTtoArray(TreeNode* root, vector<int>& memo){
        if(root == nullptr)
            return;

        BSTtoArray(root->left, memo);
        memo.push_back(root->val);
        BSTtoArray(root->right, memo);
    }
};
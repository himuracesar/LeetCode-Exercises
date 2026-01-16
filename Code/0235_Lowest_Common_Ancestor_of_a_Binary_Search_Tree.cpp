/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int start = 0;
        int end = 0;

        if(p->val > q->val){
            start = q->val;
            end = p->val;
        } else {
            start = p->val;
            end = q->val;
        }

        return lowestCommonAncestor(root, start, end);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, int start, int end){
        if(root->val >= start && root->val <= end)
            return root;

        if(root->val < start)
            return lowestCommonAncestor(root->right, start, end);
        if(root->val > end)
            return lowestCommonAncestor(root->left, start, end);

        return nullptr;
    }
};
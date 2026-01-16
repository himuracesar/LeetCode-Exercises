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
    int goodNodes(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return countGoodNodes(root, root->val);
    }

    int countGoodNodes(TreeNode* root, int maxVal){
        if(root == nullptr)
            return 0;

        int maxi = max(maxVal, root->val);
        int total = countGoodNodes(root->left, maxi) + countGoodNodes(root->right, maxi);

        if(root->val >= maxVal)
            total++;

        return total;
    }
};
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        
        InOrder(root, nodes);
        
        return nodes;
    }
    
    void InOrder(TreeNode* root, vector<int>& v)
    {
        if(!root)
            return;
            
        if(root->left)
            InOrder(root->left, v);
        
        v.push_back(root->val);
        
        if(root->right)
            InOrder(root->right, v);
    }
};
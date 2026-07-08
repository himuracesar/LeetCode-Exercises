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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> list;
        vector<int> v;
        pathSum(root, targetSum, 0, v, list);

        return list;
    }

    void pathSum(TreeNode* root, int targetSum, int currentSum, vector<int> v, vector<vector<int>>& list){
        if(root == nullptr)
            return;

        v.push_back(root->val);
        currentSum += root->val;
        if(root->left == nullptr && root->right == nullptr && currentSum == targetSum){
            list.push_back(v);
            return;
        }

        pathSum(root->left, targetSum, currentSum, v, list);
        pathSum(root->right, targetSum, currentSum, v, list);
    }
};
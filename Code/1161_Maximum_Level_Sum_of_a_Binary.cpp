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
    int maxLevelSum(TreeNode* root) {
        vector<int> sums;
        sums.push_back(0);
        getSumsByLevel(root, sums, 1);

        int maxNum = INT_MIN;
        int level = 0;
        for(auto i = 0; i < sums.size(); i++){
            //cout << sums[i] << endl;
            if(sums[i] > maxNum){
                maxNum = sums[i];
                level = i + 1;
            }
        }

        return level;
    }

    void getSumsByLevel(TreeNode* root, vector<int>& sums, int level){
        if(root){
            if(level - 1 >= sums.size())
                sums.push_back(root->val);
            else
                sums[level - 1] += root->val;

            getSumsByLevel(root->left, sums, level + 1);
            getSumsByLevel(root->right, sums, level + 1);
        }
    }
};
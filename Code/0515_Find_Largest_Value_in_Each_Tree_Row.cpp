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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> qNodes;
        queue<int> qLevels;

        vector<int> numsMax;
        int numMax = INT_MIN;

        if(root){
            qNodes.push(root);
            qLevels.push(1);
            numMax = root->val;
        } else {
            return numsMax;
        }

        int levelAnt = 1;
        while(!qNodes.empty()){
            TreeNode* node = qNodes.front();

            if(qLevels.front() != levelAnt){
                numsMax.push_back(numMax);
                numMax = node->val;
                levelAnt = qLevels.front();
            } else {
                numMax = max(numMax, node->val);
            }

            if(node->left){
                qNodes.push(node->left);
                qLevels.push(qLevels.front() + 1);
            }

            if(node->right){
                qNodes.push(node->right);
                qLevels.push(qLevels.front() + 1);
            }

            qNodes.pop();
            qLevels.pop();
        }

        numsMax.push_back(numMax);

        return numsMax;

    }
};
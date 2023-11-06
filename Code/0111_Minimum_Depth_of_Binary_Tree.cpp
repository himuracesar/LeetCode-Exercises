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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> nodes;
        queue<int> levels;

        if(root){
            nodes.push(root);
            levels.push(1);
        }

        while(!nodes.empty()){
            TreeNode* pNode = nodes.front();
            int level = levels.front();

            nodes.pop();
            levels.pop();

            if(!pNode->left && !pNode->right)
                return level;
            
            if(pNode->left){
                nodes.push(pNode->left);
                levels.push(level + 1);
            }
            if(pNode->right){
                nodes.push(pNode->right);
                levels.push(level + 1);
            }
        }

        return 0;
    }
};
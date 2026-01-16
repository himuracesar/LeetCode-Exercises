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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;

        queue<TreeNode*> q;

        if(root != nullptr)
            q.push(root);

        int nodesCurrentLevel = 1;
        int nodesNextLevel = 0;
        int counter = 0;

        vector<int> values;

        while(!q.empty()){
            TreeNode* pNode = q.front();
            q.pop();

            counter++;
            values.push_back(pNode->val);

            if(pNode->left != nullptr){
                nodesNextLevel++;
                q.push(pNode->left);
            }
            if(pNode->right != nullptr){
                nodesNextLevel++;
                q.push(pNode->right);
            }

            if(counter == nodesCurrentLevel){
                nodesCurrentLevel = nodesNextLevel;
                nodesNextLevel = 0;
                counter = 0;
                ans.push_back(values);
                values.clear();
            }
        }

        return ans;
    }
};
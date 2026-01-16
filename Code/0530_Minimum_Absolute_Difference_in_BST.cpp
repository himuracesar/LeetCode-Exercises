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
    int getMinimumDifference(TreeNode* root) {
        priority_queue<int> pq;
        readTree(root, pq);

        int minDiff = INT_MAX;
        int lastVal = 0;
        while(!pq.empty())
        {
            int dif = abs(pq.top() - lastVal);
            lastVal = pq.top();
            pq.pop();

            minDiff = min(minDiff, dif);
        }

        return minDiff;
    }

    void readTree(TreeNode* root, priority_queue<int>& pq){
        if(root)
            pq.push(root->val);

        if(root->left){
            readTree(root->left, pq);
        }
        if(root->right){
            readTree(root->right, pq);
        }
    }
};
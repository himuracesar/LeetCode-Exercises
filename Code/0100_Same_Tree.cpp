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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //cout << "p:: " << p << " q:: " << q << endl;
        if(p == nullptr && q == nullptr)
        {
            //cout << "nullptr" << endl;
            return true;
        }
        
        if((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr))
        {
            //cout << "false 1" << endl;
            return false;
        }
        
        if(p->val == q->val)
        {
            //cout << "p->val:: " << p->val << " q->val:: " << q->val << endl;
            if(isSameTree(p->left, q->left))
                return isSameTree(p->right, q->right);
            else
                return false;
        }
        else
            return false;
        
    }
};
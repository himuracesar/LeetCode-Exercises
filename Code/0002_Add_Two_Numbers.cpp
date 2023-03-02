/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int ac = 0;
        int sum = 0;
            
        ListNode* pRoot = nullptr;
            
        while(l1 || l2 || ac > 0)
        {
            if(l1)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2)
            {
                sum += l2->val;
                l2 = l2->next;
            }
            
            sum += ac;
            ac = 0;
            
            if(sum >= 10)
            {
                sum = sum - 10;
                ac++;
            }
            
            pRoot = InsertNode(pRoot, sum);
            sum = 0;
        }
        
        return pRoot;
    }
    
    ListNode* InsertNode(ListNode* root, int val)
    {
        if(!root)
            root = new ListNode(val);
        else
            root->next = InsertNode(root->next, val);
        
        return root;
    }
};
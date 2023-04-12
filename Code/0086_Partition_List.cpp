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
    ListNode* partition(ListNode* head, int x) {
        ListNode* pLeftHead = nullptr;
        ListNode* pRightHead = nullptr;

        while(head != nullptr)
        {
            if(head->val < x)
                pLeftHead = InsertNode(pLeftHead, head->val);
            else
                pRightHead = InsertNode(pRightHead, head->val);
                
            head = head->next;
        }
        
        while(pRightHead)
        {
            pLeftHead = InsertNode(pLeftHead, pRightHead->val);
            pRightHead = pRightHead->next;
        }

        ListNode* pNode = head;
        while(pNode != nullptr)
        {
            pNode = head->next;
            delete head;
            head == nullptr;
        }

        return pLeftHead;
    }

    ListNode* InsertNode(ListNode* head, int val)
    {
        if(head == nullptr)
        {
            head = new ListNode(val);
        }
        else
        {
            head->next = InsertNode(head->next, val);
        }

        return head;
    }
};
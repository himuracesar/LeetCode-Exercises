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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list = nullptr;
        while(list1 != nullptr || list2 != nullptr)
        {
            if(list1 != nullptr && list2 != nullptr)
            {
                if(list1->val <= list2->val)
                {
                    list = InsertNode(list, list1->val);
                    list1 = list1->next;
                }
                else
                {
                    list = InsertNode(list, list2->val);
                    list2 = list2->next;
                }
            }
            else if(list1 != nullptr && list2 == nullptr)
            {
                list = InsertNode(list, list1->val);
                list1 = list1->next;
            }
            else if(list2 != nullptr && list1 == nullptr)
            {
                list = InsertNode(list, list2->val);
                list2 = list2->next;
            }
        }
        
        return list;
    }
    
    ListNode* InsertNode(ListNode* root, int val)
    {
        if(root == nullptr)
        {
            root = new ListNode(val);
        }
        else
        {
            root->next = InsertNode(root->next, val);
        }
        
        return root;
    }
};
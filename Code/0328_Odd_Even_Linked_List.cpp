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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddList = nullptr;
        ListNode* evenList = nullptr;

        bool turn = false;
        while(head){
            if(turn){
                evenList = addNode(evenList, head->val);
            } else {
                oddList = addNode(oddList, head->val);
            }
            
            head = head->next;
            turn = !turn;
        }

        return mergeLists(oddList, evenList);
    }

    ListNode* addNode(ListNode* head, int val){
        if(head == nullptr){
            head = new ListNode(val);
        } else {
            head->next = addNode(head->next, val);
        }

        return head;
    }

    ListNode* mergeLists(ListNode* odd, ListNode* even){
        if(odd == nullptr){
            odd = even;
        } else {
            odd->next = mergeLists(odd->next, even);
        }

        return odd;
    }
};
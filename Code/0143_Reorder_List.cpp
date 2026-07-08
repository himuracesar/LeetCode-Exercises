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
    void reorderList(ListNode* head) {
        vector<ListNode*> nodes;

        while(head != nullptr){
            nodes.push_back(head);
            head = head->next;
        }

        int start = 0;
        int end = nodes.size()-1;
        while(start <= end){
            if(start > 0)
                nodes[end+1]->next = nodes[start];

            if(start < end){
                nodes[start]->next = nodes[end];
                nodes[end]->next = nullptr;
            } else {
                nodes[start]->next = nullptr;
            }

            start++;
            end--;
        }
    }
};
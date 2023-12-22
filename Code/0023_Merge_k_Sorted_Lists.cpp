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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto i = 0; i < lists.size(); i++){
            ListNode* pNode = lists[i];
            while(pNode){
                pq.push(pNode->val);

                pNode = pNode->next;
            }
        }

        ListNode* head = nullptr;
        while(!pq.empty()){
            head = insertNode(head, pq.top());
            pq.pop();
        }

        return head;
    }

    ListNode* insertNode(ListNode* head, int val){
        if(head == nullptr){
            head = new ListNode(val);
        } else {
            head->next = insertNode(head->next, val);
        }

        return head;
    }
};
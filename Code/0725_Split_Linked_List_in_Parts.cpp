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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> nodes;
        vector<ListNode*> split;
        int n = 0;

        while(head){
            nodes.push_back(head);
            head = head->next;
            n++;
        }        

        int numElements = n / k;
        int res = n % k;
        int index = 0;
        for(auto i = 0; i < k; i++){
            int numMembers = numElements;
            if(res > 0){
                numMembers++;
                res--;
            }
            numMembers = (numMembers == 0) ? 1 : numMembers;

            if(index < nodes.size())
                split.push_back(nodes[index]);
            else
                split.push_back(nullptr);

            if(index + numMembers - 1 < nodes.size())
                nodes[index + numMembers - 1]->next = nullptr;
            index += numMembers;
        }

        return split;
    }
};
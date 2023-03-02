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
    ListNode* swapPairs(ListNode* head) {
        vector<ListNode*> nodes;
        
        while(head)
        {
            nodes.push_back(head);
            head = head->next;
        }
        
        if(nodes.size() == 0)
        {
            //cout << "size 0" << endl;
            return nullptr;
        }
        else if(nodes.size() < 2)
        {
            //cout << "size <2" << endl;
            return nodes[0];
        }
        
        int index = nodes.size();
        index = (index % 2 == 0) ? index - 1 : index - 2;
        
        while(index > 0)
        {
            //cout << "index:: " << index << endl;
            ListNode* _pAuxNode = nodes[index];
            nodes[index] = nodes[index - 1];
            nodes[index - 1] = _pAuxNode;
            nodes[index - 1]->next = nodes[index];
            
            if(index + 1 >= nodes.size())
                nodes[index]->next = nullptr;
            else
                nodes[index]->next = nodes[index + 1];
            
            index -= 2;
        }
        
        return nodes[0];
    }
};
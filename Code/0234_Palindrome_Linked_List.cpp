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
    bool isPalindrome(ListNode* head) {
        vector<int> pal;

        while(head != nullptr){
            pal.push_back(head->val);
            head = head->next;
        }

        int start = 0;
        int end = pal.size() - 1;

        while(start < end){
            if(pal[start] != pal[end])
                return false;

            start++;
            end--;
        }

        return true;
    }
};
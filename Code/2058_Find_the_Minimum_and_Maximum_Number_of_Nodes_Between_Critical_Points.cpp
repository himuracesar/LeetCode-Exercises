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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> val1 = { INT_MIN, - 1 };
        vector<int> val2 = { INT_MIN, - 1 };
        vector<int> val3 = { INT_MIN, - 1 };

        int node = 0;
        int minDistance = INT_MAX;

        vector<vector<int>> points;

        while(head != nullptr){
            node++;

            if(node == 1){
                val1[0] = head->val;
                val1[1] = node;
            } else if(node == 2){
                val2[0] = head->val;
                val2[1] = node;
            } else {
                if(val3[0] > INT_MIN){
                    val1 = val2;
                    val2 = val3;
                } 
                    
                val3[0] = head->val;
                val3[1] = node;

                vector<int> pt;
                if(val1[0] > val2[0] && val2[0] < val3[0]){
                    points.push_back(val2);
                } else if(val1[0] < val2[0] && val2[0] > val3[0]){
                    points.push_back(val2);
                }

                if(points.size() > 1){
                    int d = points[points.size() - 1][1] - points[points.size() - 2][1];
                    minDistance = min(minDistance, d); 
                }

                head = head->next;
            }
        }

        int maxDistance = -1;
        if(points.size() > 1){
            maxDistance = points[points.size() - 1][1] - points[0][1];
        }

        minDistance = (minDistance == INT_MAX) ? -1 : minDistance;

        vector<int> ans = { minDistance, maxDistance };

        return ans;
    }
};
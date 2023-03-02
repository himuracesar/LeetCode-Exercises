/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null)
            return null;
        
        int lastNumber = -Integer.MAX_VALUE;
        
        List<ListNode> list = new ArrayList<ListNode>();
        
        while(head != null)
        {
            if(head.val != lastNumber)
            {
                lastNumber = head.val;
                list.add(head);
            }
            
            head = head.next;
        }
        
        for(int i = 0; i < list.size(); i++)
        {
            if(i < list.size() - 1)
                list.get(i).next = list.get(i + 1);
            else
                list.get(i).next = null;
        }
        
        return list.get(0);
    }
}
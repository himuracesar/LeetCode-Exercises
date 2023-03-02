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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        List<ListNode> list = new ArrayList<ListNode>();
        
        while(head != null)
        {
            list.add(head);
            head = head.next;
        }
        
        if(list.size() <= 1 )
            return null;
        else{
            int index = list.size() - n;
            
            ListNode nodeToRemove = list.get(index);
            if(index > 0){
                ListNode node = list.get(index - 1);
                node.next = nodeToRemove.next;
            }
            
            nodeToRemove = null;
            list.remove(index);
        }
        
        return list.get(0);
    }
}
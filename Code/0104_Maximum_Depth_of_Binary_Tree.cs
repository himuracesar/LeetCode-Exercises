/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
    public int MaxDepth(TreeNode root) {
        int depth = 0;
        
        return GetDepth(root, depth);  
    }
    
    public int GetDepth(TreeNode root, int depth)
    {
        if(root != null)
        {
            depth++;
            depth = Math.Max(GetDepth(root.left, depth), GetDepth(root.right, depth));
        }
        
        return depth;
    }
}
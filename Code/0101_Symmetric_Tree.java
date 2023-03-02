/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        if(root == null)
            return true;
        
        List<Integer> left = new ArrayList<Integer>();
        getLeftSubTree(root.left, left);
        
        List<Integer> right = new ArrayList<Integer>();
        getRightSubTree(root.right, right);
        
        if(left == null && right == null)
            return false;
        
        if(left == null || right == null)
            return false;
        
        if(left.size() != right.size())
            return false;
        
        for(int i = 0; i < left.size(); i++)
        {
            //System.out.println("left:: " + left.get(i) + " right:: " + right.get(i) );
            if(left.get(i) != right.get(i))
                return false;
        }
        
        return true;
    }
    
    public void getLeftSubTree(TreeNode root, List<Integer> list)
    {
        if(root != null)
        {
            list.add(root.val);
            //System.out.println("Add Left:: " + root.val);
            getLeftSubTree(root.left, list);
            getLeftSubTree(root.right, list);
        }
        else
        {
            list.add(-1);
            //System.out.println("Add Left -1");
        }
    }
    
    public void getRightSubTree(TreeNode root, List<Integer> list)
    {
        if(root != null)
        {
            list.add(root.val);
            //System.out.println("Add Right:: " + root.val);
            getRightSubTree(root.right, list);
            getRightSubTree(root.left, list);
        }
        else
        {
            list.add(-1);
            //System.out.println("Add right:: -1");
        }
    }
}
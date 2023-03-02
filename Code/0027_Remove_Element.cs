public class Solution {
    public int RemoveElement(int[] nums, int val) {
                
        int l = nums.Length;
        int p = l - 1;
        int i = 0;
        
        if(p < 0)
            return 0;
        
        while(i <= p)
        {
            if(nums[i] == val)
            {
                l--;
                while(p >= 0 && i < p && nums[p] == val)
                {
                    l--;
                    p--;
                }
                
                if(p < 0)
                    break;
                
                //Console.Write("p:: " + p);
                int aux = nums[i];
                nums[i] = nums[p];
                nums[p--] = aux;
            }
            
            i++;
        }
        
        l = (l < 0) ? 0 : l;
        
        return l;
    }
}
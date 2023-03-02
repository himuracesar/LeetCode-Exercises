class Solution {
    public boolean containsDuplicate(int[] nums) {
        HashMap<Integer, Integer> hmNums = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < nums.length; i++)
        {
            //System.out.println(nums[i] + " key:: " + hmNums.get(nums[i]));
            if(hmNums.get(nums[i]) == null)
                hmNums.put(nums[i], nums[i]);
            else
                return true;
        }
        
        return false;
    }
}
class Solution {
    public int[] twoSum(int[] nums, int target) {
        List<Integer> list = new ArrayList<Integer>();
        
        for(int i = 0; i < nums.length; i++)
        {
            for(int j = i + 1; j < nums.length; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    list.add(i);
                    list.add(j);
                }
            }
        }
        
        int[] indices = new int[list.size()];
        for(int i = 0; i < list.size(); i++)
        {
            indices[i] = list.get(i);
        }
        
        return indices;
    }
}
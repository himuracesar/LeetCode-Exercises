public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int n = nums.Length;
        int[] arr = new int[2];
        int value = 0;
        
        Dictionary<int, int> dic = new Dictionary<int, int>();
        
        for(int i = 0; i < n; i++)
        {
            int t = target - nums[i];
            if(dic.TryGetValue(t, out value))
            {
                arr[0] = i;
                arr[1] = value;
                break;
            }
            else
            {
                if(!dic.TryGetValue(nums[i], out value))
                    dic.Add(nums[i], i);
            }
        }
        
        return arr;
    }
}
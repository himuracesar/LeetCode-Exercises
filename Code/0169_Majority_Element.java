class Solution {
    public int majorityElement(int[] nums) {
        int times = nums.length / 2;

        HashMap<Integer, Integer> freqs = new HashMap<Integer, Integer>();

        for(var i = 0; i < nums.length; i++){
            if(freqs.get(nums[i]) == null)
                freqs.put(nums[i], 1);
            else
                freqs.put(nums[i], freqs.get(nums[i]) + 1);

            if(freqs.get(nums[i]) > times)
                return nums[i];
        }

        return 0;
    }
}
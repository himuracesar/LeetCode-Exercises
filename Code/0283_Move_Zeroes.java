class Solution {
    public void moveZeroes(int[] nums) {
        int p0 = 0;
        int p1 = p0+1;

        while(p0 < p1 && p1 < nums.length){
            if(nums[p0] == 0 && nums[p1] != 0){
                int aux = nums[p0];
                nums[p0] = nums[p1];
                nums[p1] = aux;
            }

            while(p0 < nums.length && nums[p0] != 0)
                p0++;

            p1 = p0+1;
            while(p1 < nums.length && nums[p1] == 0)
                p1++;
        }
    }
}
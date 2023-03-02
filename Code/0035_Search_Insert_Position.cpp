class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        int index = 0;
        
        while(start <= end)
        {
            mid = (start + end) / 2;
            
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
            {
                end = mid - 1;
                index = end;
            }
            else if(nums[mid] < target)
            {
                start = start + 1;
                index = start;
            }
        }
        
        if(index < 0)
            return 0;
        else if(index >= nums.size())
            return nums.size();
        else if(nums[index] < target)
            return index + 1;
        //else if(nums[index] > target)
            //return index;
        
        return index;
    }
};
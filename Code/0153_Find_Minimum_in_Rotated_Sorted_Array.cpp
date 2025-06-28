class Solution {
public:
    int findMin(vector<int>& nums) {
        int first = nums[0];
        int last = nums[nums.size() - 1];

        if(first < last || first == last)
            return first;

        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        while(start < end){
            mid = (start + end) / 2;

            if(nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if(nums[mid] < nums[mid - 1])
                return nums[mid];

            if(first > nums[mid]){
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return -1;
    }
};
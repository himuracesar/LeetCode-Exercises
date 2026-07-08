class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> rsum(nums.size(), 0);
        rsum[0] = nums[0];

        for(auto i = 1; i < nums.size(); i++){
            rsum[i] = rsum[i-1] + nums[i];
        }

        return rsum;
    }
};
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo = vector<int>(nums.size(), 1);
        int maxSubs = 1;
        
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int j= i  - 1; j >= 0; j--){
                if(nums[j] < nums[i]){
                    memo[j] = max(memo[j], memo[i] + 1);
                    maxSubs = max(memo[j], maxSubs);
                }
            }
        }

        return maxSubs;
    }
};
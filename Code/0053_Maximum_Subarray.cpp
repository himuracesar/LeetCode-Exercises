class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int maxn = INT_MIN;
        
        for(auto i = 0; i < n; i++)
        {
            sum += nums[i];
            
            maxn = max(maxn, sum);
            
            if(sum < 0)
                sum = 0;
        }
        
        return maxn;
    }
};
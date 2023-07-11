class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long sumRight = 0;
        long sumLeft = 0;
        long total = 0;
        int ways = 0;

        for(auto i = 0; i < nums.size(); i++)
            total += nums[i];

        for(auto i = 0; i < nums.size() - 1; i++)
        {
            sumLeft += nums[i];
            sumRight = total - sumLeft;
            if(sumLeft >= sumRight)
                ways++;
        }

        return ways;
    }
};
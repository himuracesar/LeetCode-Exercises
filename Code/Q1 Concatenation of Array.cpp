class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> ans(nums.size() * 2, 0);

        int offset = nums.size();

        for(auto i = 0; i < nums.size(); i++){
            ans[i] = nums[i];
            ans[offset++] = nums[i];
        }

        return ans;
    }
};
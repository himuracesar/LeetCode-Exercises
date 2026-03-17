class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int half = nums.size() / 2;
        int odd = (nums.size() % 2 != 0) ? half + 1 : 0 ;
        int sum = (nums.size() + 1) * (nums.size() / 2) + odd;

        vector<int> cache (nums.size() + 1, 0);
        vector<int> ans;

        for(auto i = 0; i < nums.size(); i++){
            if(cache[nums[i]] == 0){
                sum -= nums[i];
                cache[nums[i]] = 1;
            } else {
                ans.push_back(nums[i]);
            }
        }

        ans.push_back(sum);

        return ans;
    }
};
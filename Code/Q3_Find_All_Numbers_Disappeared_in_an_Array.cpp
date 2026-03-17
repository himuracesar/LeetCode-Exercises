class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> cache(nums.size() + 1, 0);
        vector<int> ans;

        for(auto i = 0; i < nums.size(); i++)
            cache[nums[i]] = 1;

        for(auto i = 1; i < cache.size(); i++){
            if(cache[i] == 0)
                ans.push_back(i);
        }

        return ans;
    }
};
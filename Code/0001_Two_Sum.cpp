class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> numsearch;
        vector<int> res;
        res.resize(2);

        for(auto i = 0; i < nums.size(); i++)
        {
            if(numsearch.find(nums[i]) != numsearch.end())
            {
                res[0] = numsearch[nums[i]];
                res[1] = i;

                return res;
            }
            else
            {
                int r = target - nums[i];
                numsearch[r] = i;
            }
        }

        return res;
    }
};
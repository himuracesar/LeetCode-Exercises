class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> nexist;

        for(auto i = 0; i < nums.size(); i++)
        {
            if(nexist.find(nums[i]) != nexist.end())
                return true;
            else
                nexist[nums[i]] = nums[i];
        }

        return false;
    }
};
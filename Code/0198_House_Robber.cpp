class Solution {
public:
    int rob(vector<int>& nums) {
        for(auto i = 0; i < nums.size(); i++)
            memoization.push_back(-1);

        if(nums.size() > 1)
        {
            GetMoney(nums, 0);
            GetMoney(nums, 1);
        }
        else
            return nums[0];

        return max(memoization[0], memoization[1]);
    }

    int GetMoney(vector<int>& nums, int index)
    {
        if(memoization[index] == -1)
        {
            int m1 = nums[index];
            int m2 = nums[index];

            if(index + 2 < nums.size())
                m1 += GetMoney(nums, index + 2);

            if(index + 3 < nums.size())
                m2 += GetMoney(nums, index + 3);

            memoization[index] = max(m1, m2);
        }

        return memoization[index];
    }

private:
    vector<int> memoization;
};
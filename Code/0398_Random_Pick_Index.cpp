class Solution {
public:
    Solution(vector<int>& nums) {
        for(auto i = 0; i < nums.size(); i++){
            numbers[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        if(numbers[target].size() == 1)
            return numbers[target][0];
        else{
            int index = rand() % numbers[target].size();
            return numbers[target][index];
        }
    }

private:
    map<int, vector<int>> numbers;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
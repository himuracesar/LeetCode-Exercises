class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> combs(target + 1, 0);
        combs[0] = 1;

        for(auto i = 0; i <= target; i++){
            if(combs[i] == 0)
                continue;
            for(auto j = 0; j < nums.size(); j++){
                int index = i + nums[j];
                if(index < combs.size()){
                    combs[index] += combs[i];
                }
            }
        }
        
        return combs[target];
    }
};
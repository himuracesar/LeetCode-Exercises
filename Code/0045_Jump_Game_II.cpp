class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> cache;
        for(auto i = 0; i < nums.size() - 1; i++)
            cache.push_back(INT_MAX);

        if(nums.size() <= 1)
            return 0;

        return jump(nums, 0, cache);
    }

    int jump(vector<int>& nums, int index, vector<int>& cache){
        if(index + nums[index] >= nums.size() - 1){
            return 1;
        } else {
            int end = nums[index] + index;
            for(auto i = index + 1; i <= end; i++){
                if(cache[i] == INT_MAX)
                    cache[i] = min(jump(nums, i, cache), cache[i]);
                
                if(cache[i] > -1 && cache[i] < INT_MAX)
                    cache[index] = min(cache[index], cache[i] + 1);
            }
        }

        return cache[index];
    }
};
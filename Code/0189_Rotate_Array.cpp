class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> aux(nums.size(), 0);

        for(auto i = 0; i < nums.size(); i++){
            int newIndex = (k+i) % nums.size();
            aux[newIndex] = nums[i];
        }

        for(auto i = 0; i < nums.size(); i++){
            nums[i] = aux[i];
        }
    }
};
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max1 = 0;
        int counter = 0;
        for(auto i = 0; i < nums.size(); i++){
            if(nums[i] == 1){
                counter++;
            } else {
                max1 = max(max1, counter);
                counter = 0;
            }
        }

        max1 = max(max1, counter);

        return max1;
    }
};
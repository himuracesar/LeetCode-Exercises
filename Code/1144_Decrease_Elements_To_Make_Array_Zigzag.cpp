class Solution {
public:
    int movesToMakeZigzag(vector<int>& nums) {
        int even = getMoves(nums, 0);
        int odd = getMoves(nums, 1);

        return min(even, odd);
    }

    int getMoves(vector<int>& nums, int start){
        int moves = 0;
        int a1 = INT_MAX;
        int a2 = INT_MAX;
        for(auto i = start; i < nums.size(); i += 2){
            a1 = (i-1 >= 0) ? nums[i-1] : INT_MAX;
            a2 = (i+1 < nums.size()) ? nums[i+1] : INT_MAX;

            int minNum = min(a1, a2);
            if(minNum <= nums[i]){
                moves += nums[i] - minNum + 1;
            }
        }

        return moves;
    }
};
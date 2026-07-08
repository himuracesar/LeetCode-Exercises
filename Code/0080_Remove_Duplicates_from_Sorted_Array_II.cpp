class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int counter = 0;
        int k = 0;
        int last = INT_MAX;
        int p1 = -1;
        int p2 = -1;

        for(auto i = 0; i < nums.size(); i++){
            if(nums[i] == last){
                counter++;
                if(counter > 2){
                    nums[i] = INT_MAX;
                    p1 = (p1 == -1) ? i : p1;
                    k++;
                }
            } else {
                p2 = (p2 == -1 && p1 != -1) ? i : p2;
                last = nums[i];
                counter = 1;
            }
        }

        k = nums.size() - k;
        while(p1 < k && p1 < p2 && p2 < nums.size()){
            nums[p1] = nums[p2];
            nums[p2] = INT_MAX;

            while(nums[p1] != INT_MAX)
                p1++;
            while(p2 < nums.size() && nums[p2] == INT_MAX)
                p2++;
        }

        return k;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        answer.push_back(1);

        int p = 1;

        //prefix
        for(auto i = 1; i < nums.size(); i++){
            p *= nums[i - 1];
            answer.push_back(p);
        }

        //postfix
        p = 1;
        for(int i = nums.size() - 2; i >= 0; i--){
            p *= nums[i + 1];
            answer[i] *= p; 
        }

        return answer;
    }
};
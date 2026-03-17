class Solution {
public:
    int calculate(string s) {
        vector<int> nums;
        vector<char> ops;

        int total = 0;
        int an = 0;

        for(auto i = 0; i < s.length(); i++){
            if(s[i] == ' ')
                continue;

            int n = s[i] - '0';
            if(n >= 0 && n <= 9){
                an = an * 10 + n;
            } else {
                if(pendingOp(nums, ops, an)){
                    ops[ops.size()-1] = s[i];
                } else {
                    ops.push_back(s[i]);
                    nums.push_back(an);
                }

                an = 0;
            }
        }

        if(!pendingOp(nums, ops, an)){
            nums.push_back(an);
        }

        total = nums[0];
        for(auto i = 1; i < nums.size(); i++) {
            char op = ops[i-1];
            if(op == '+')
                total += nums[i];
            else
                total -= nums[i];
        }
        
        return total;
    }

    bool pendingOp(vector<int>& nums, vector<char>& ops, int an){
        int p1 = nums.size() - 1;
        int p2 = ops.size() - 1;
        if(ops.size() > 0 && (ops[p2] == '*' || ops[p2] == '/')){
            if(ops[p2] == '*')
                nums[p1] *= an;
            else
                nums[p1] /= an;

            return true;
        }

        return false;
    }
};
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> ans;
        ans.push_back(1);
        ans.push_back(10);

        int nums = 9;
        int substracts = 0;
        for(auto i = 2; i <= n; i++){
            nums *= 9 - substracts++;
            ans.push_back(nums + ans[i - 1]);
        }

        return ans[n];
    }
};
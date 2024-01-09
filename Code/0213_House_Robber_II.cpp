class Solution {
public:
    int rob(vector<int>& nums) {
        vector<vector<int>> robs;
        vector<int> row;
        for(auto i = 0; i < nums.size(); i++){
            if(i < nums.size() - 1)
                row.push_back(nums[i]);
            else
                row.push_back(0);
        }

        robs.push_back(row);
        robs.push_back(row);

        robs[1][0] = INT_MIN;
        robs[1][nums.size() - 1] = nums[nums.size() - 1];

        for(int i = nums.size() - 3; i >= 0; i--){
            int h1 = max(robs[0][i], robs[0][i] + robs[0][i + 2]);
            int h2 = max(robs[1][i], robs[1][i] + robs[1][i + 2]);

            if(i + 3 < nums.size()){
                h1 = max(robs[0][i] + robs[0][i + 3], h1);
                h2 = max(robs[1][i] + robs[1][i + 3], h2);
            }

            robs[0][i] = h1;
            robs[1][i] = h2;

            //cout << "robs[0][" << i << "]:: " << robs[0][i] << " :::: " << "robs[1][" << i << "]:: " << robs[1][i] << endl; 
        }

        int end = min(2, (int)nums.size() - 1);
        int maxrobber = 0;
        for(auto i = 0; i <= end; i++){
            //cout << robs[0][i] << " --- " << robs[1][i] << endl;
            maxrobber = max(maxrobber, max(robs[0][i], robs[1][i]));
        }

        return maxrobber;
    }
};
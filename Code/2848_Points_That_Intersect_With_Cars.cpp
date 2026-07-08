class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(nums.begin(), nums.end());

        int gaps = 0;
        int lastNum = 0;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(auto i = 0; i < nums.size(); i++){
            minVal = min(minVal, nums[i][0]);
            maxVal = max(maxVal, nums[i][1]);

            while(!pq.empty() && nums[i][0] > pq.top()){
                lastNum = pq.top();
                pq.pop();
            } 
            
            if(pq.empty() && i > 0)
                gaps += nums[i][0] - lastNum - 1;

            pq.push(nums[i][1]);
        }
        
        int line = maxVal - minVal + 1;
        
        return line - gaps;
    }
};
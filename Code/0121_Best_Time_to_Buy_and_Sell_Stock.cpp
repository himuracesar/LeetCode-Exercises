class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int profit = 0;
        int pivot = 0;
        
        for(auto i = 1; i < prices.size(); i++)
        {
            profit = prices[i] - prices[pivot];
            if(profit < 0)
                pivot = i;
            else
                maxProfit = max(maxProfit, profit);
        }
        
        return maxProfit;
    }
};
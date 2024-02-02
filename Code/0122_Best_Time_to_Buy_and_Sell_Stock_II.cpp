class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int stock = 0;

        bool canBuy = true;
        for(auto i = 0; i < prices.size(); i++){
            //cout << i << endl;
            if(i == prices.size() - 1 && !canBuy && stock < prices[i]) {
                profit += prices[i] - stock;
            } else if(!canBuy && prices[i] > prices[i + 1]){
                profit += prices[i] - stock;
                canBuy = true;
                stock = 0;
            } else if(canBuy && i + 1 < prices.size() && prices[i] < prices[i + 1]){
                stock = prices[i];
                canBuy = false;
            }
        }

        return profit;
    }
};
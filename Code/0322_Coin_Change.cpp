class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<unsigned int> totalCoins(amount+1, INT_MAX);
        totalCoins[0] = 0;

        for(auto i = 0; i <= amount; i++){
            if(totalCoins[i] == INT_MAX)
                continue;
            for(auto j = 0; j < coins.size(); j++){
                unsigned int index = i + (unsigned int)coins[j];
                if(index < totalCoins.size()){
                    unsigned int amt = totalCoins[i] + 1;
                    totalCoins[index] = min(totalCoins[index], amt);
                }
            }
        }

        return totalCoins[amount] == INT_MAX ? -1 : totalCoins[amount];
    }
};
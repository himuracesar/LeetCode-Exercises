class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int total = 0;

        for(auto i = 0; i < piles.size(); i++){
            pq.push(piles[i]);
            total += piles[i];
        }

        for(auto i = 1; i <= k; i++){
            int rem = floor(pq.top() / 2.0f);
            total -= rem;

            int numStones = pq.top() - rem;
            pq.pop();
            pq.push(numStones);
        }

        return total;
    }
};
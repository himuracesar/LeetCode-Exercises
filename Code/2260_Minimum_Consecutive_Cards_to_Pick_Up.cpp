class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        map<int, int> locations;
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto i = 0; i < cards.size(); i++){
            if(locations.find(cards[i]) == locations.end()){
                locations[cards[i]] = i;
            } else {
                pq.push(i - locations[cards[i]] + 1);
                locations[cards[i]] = i;
            }
        }

        if(pq.empty())
            return -1;
        
        return pq.top();
    }
};
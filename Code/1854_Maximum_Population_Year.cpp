class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        priority_queue<int, vector<int>, greater<int>> pq;

        sort(logs.begin(), logs.end());

        int maxYear = 0;
        int maxPeople = 0;
        int currentPeople = 0;

        for(auto i = 0; i < logs.size(); i++){
            if(!pq.empty() && pq.top() <= logs[i][0]){
                currentPeople--;
                pq.pop();
            }
            
            pq.push(logs[i][1]);
            
            currentPeople++;
            if(currentPeople > maxPeople){
                maxPeople = currentPeople;
                maxYear = logs[i][0];
            }
        }

        return maxYear;
    }
};
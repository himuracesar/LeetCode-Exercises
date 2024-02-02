class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(auto i = 0; i < intervals.size(); i++){
            int aux = intervals[i][0];
            intervals[i][0] = intervals[i][1];
            intervals[i][1] = aux;
            pq.push(intervals[i]);
        }

        int removals = 0;
        int maxi = pq.top()[0];
        int mini = pq.top()[1];
        pq.pop();
        while(!pq.empty()){
            //cout << pq.top()[0] << "," << pq.top()[1] << endl;
            if(pq.top()[1] < maxi)
                removals++;
            else {
                maxi = pq.top()[0];
                mini = pq.top()[1];
            }
            
            pq.pop();
        }

        return removals;
    }
};
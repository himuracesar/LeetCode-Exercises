class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> answer;
        answer.push_back(newInterval);

        for(auto i = 0; i < intervals.size(); i++){
            int index = answer.size() - 1;
            if(intervals[i][0] > answer[index][1]){
                answer.push_back(intervals[i]);
            } else if(intervals[i][1] < answer[index][0]){
                vector<int> aux = { answer[index][0], answer[index][1] };

                answer[index][0] = intervals[i][0];
                answer[index][1] = intervals[i][1];

                answer.push_back(aux);
            } else {
                answer[index][0] = min(answer[index][0], intervals[i][0]);
                answer[index][1] = max(answer[index][1], intervals[i][1]);
            }
        }

        return answer;
    }
};
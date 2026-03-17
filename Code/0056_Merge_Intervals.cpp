class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mi;

        sort(intervals.begin(), intervals.end());
        mi.push_back(intervals[0]);

        for(auto i = 1; i < intervals.size(); i++){
            int row = mi.size()-1;
            if(intervals[i][1] < mi[row][0]){
                mi.push_back(mi[row]);
                mi[row-1] = intervals[i];
             } else if(intervals[i][0] > mi[row][1]){
                mi.push_back(intervals[i]);
             } else {
                mi[row][0] = min(mi[row][0], intervals[i][0]);
                mi[row][1] = max(mi[row][1], intervals[i][1]);
             }
        }

        return mi;
    }
};
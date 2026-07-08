class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, greater<int>> ends;

        sort(intervals.begin(), intervals.end());

        int groups = 0;
        int concurrentGroups = 0;
        int index = 0;
        while(index < intervals.size()){
            if(!ends.empty() && ends.top() < intervals[index][0]){
                concurrentGroups--;
                ends.pop();
            } else {
                concurrentGroups++;
                ends.push(intervals[index][1]);
                index++;
            }

            groups = max(groups, concurrentGroups);
        }

        return groups;
    }
};
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> groups;
        map<int, vector<int>> groupManager;

        for(auto i = 0; i < groupSizes.size(); i++){
            if(groupManager.find(groupSizes[i]) != groupManager.end()){
                groupManager[groupSizes[i]].push_back(i);
            } else {
                vector<int> group;
                group.push_back(i);
                groupManager[groupSizes[i]] = group;
            }

            if(groupManager[groupSizes[i]].size() == groupSizes[i]){
                groups.push_back(groupManager[groupSizes[i]]);
                groupManager[groupSizes[i]].clear();
            }
        }

        return groups;
    }
};
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int, int> marbles;
        for(auto i = 0; i < nums.size(); i++){
            if(marbles.find(nums[i]) == marbles.end())
                marbles[nums[i]] = 1;
        }

        for(auto i = 0; i < moveFrom.size(); i++){
            if(marbles.find(moveFrom[i]) != marbles.end()){
                marbles[moveFrom[i]] = 0;
                marbles[moveTo[i]] = 1;
            }
        }

        vector<int> positions;
        for(auto m : marbles){
            if(m.second > 0)
                positions.push_back(m.first);
        }

        return positions;
    }
};
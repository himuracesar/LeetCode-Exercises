class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int numPassPlayer = abs(target[0]) + abs(target[1]);

        for(auto i = 0; i < ghosts.size(); i++){
            int numPass = abs(target[0] - ghosts[i][0]) + abs(target[1] - ghosts[i][1]);

            if(numPass <= numPassPlayer)
                return false;
        }

        return true;
    }
};
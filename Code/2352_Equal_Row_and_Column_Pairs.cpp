class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<string, int> hmRows;

        for(auto i = 0; i < grid.size(); i++){
            string row = "";
            for(auto j = 0; j < grid[0].size(); j++){
                row += to_string(grid[i][j]);
                if(j < grid[0].size())
                    row += "|";
            }

            if(hmRows.find(row) != hmRows.end())
                hmRows[row]++;
            else
                hmRows[row] = 1;
        }

        int eqs = 0;
        for(auto i = 0; i < grid.size(); i++){
            string row = "";
            for(auto j = 0; j < grid[0].size(); j++){
                row += to_string(grid[j][i]);
                if(j < grid[0].size())
                    row += "|";
            }

            if(hmRows.find(row) != hmRows.end())
                eqs += hmRows[row];
        }

        return eqs;
    }
};
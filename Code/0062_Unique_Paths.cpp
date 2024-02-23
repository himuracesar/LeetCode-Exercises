class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> paths;

        for(auto i = 0; i < m; i++){
            vector<int> row;
            for(auto j = 0; j < n; j++){
                if(j + 1 == n || i + 1 == m)
                    row.push_back(1);
                else
                    row.push_back(0);
            }
            
            paths.push_back(row);
        }

        return sumPath(paths, 0, 0);
    }

    int sumPath(vector<vector<int>>& paths, int row, int col){
        if(paths[row][col] == 0){
            if(col + 1 < paths[0].size())
                paths[row][col] += sumPath(paths, row, col + 1);
            
            if(row + 1 < paths.size())
                paths[row][col] += sumPath(paths, row + 1, col);
        }

        return paths[row][col];
    }
};
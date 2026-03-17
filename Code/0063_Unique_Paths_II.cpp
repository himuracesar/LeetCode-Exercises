class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));

        return getPaths(obstacleGrid, memo, 0, 0);
    }

    int getPaths(vector<vector<int>>& grid, vector<vector<int>>& memo, int r, int c){
        if(r == grid.size() || c == grid[0].size())
            return 0;

        if(grid[r][c] == 1){
            memo[r][c] = 0;
            return memo[r][c];
        }

        if(r == grid.size()-1 && c == grid[0].size()-1)
            return 1;

        if(memo[r][c] > -1)
            return memo[r][c];

        int right = getPaths(grid, memo, r, c+1);
        int down = getPaths(grid, memo, r+1, c);

        memo[r][c] = right + down;

        return memo[r][c];
    }
};
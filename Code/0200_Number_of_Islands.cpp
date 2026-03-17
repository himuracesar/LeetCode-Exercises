class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int numIslands = 0;

        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        queue<vector<int>> q;

        for(auto i = 0; i < grid.size(); i++){
            for(auto j = 0; j < grid[0].size(); j++){
                if(memo[i][j] > -1)
                    continue;

                if(grid[i][j] == '1')
                    q.push({ i, j });
                else
                    memo[i][j] = 0;

                while(!q.empty()){
                    vector<int> coord = q.front();
                    q.pop();

                    int r = coord[0];
                    int c = coord[1];

                    if(memo[r][c] == -1){
                        numIslands++;
                        memo[r][c] = numIslands;
                    } 
                    
                    for(auto k = -1; k < 2; k+=2){
                        int r1 = r + k;
                        int c1 = c + k;
                        if(r1 >= 0 && r1 < grid.size() && memo[r1][c] == -1 && grid[r1][c] == '1'){
                            q.push({ r1, c });
                            memo[r1][c] = numIslands;
                        }

                        if(c1 >= 0 && c1 < grid[0].size() && memo[r][c1] == -1 && grid[r][c1] == '1'){
                            q.push({ r, c1 });
                            memo[r][c1] = numIslands;
                        }
                    }
                }
            }
        }

        return numIslands;
    }
};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> pos;

        vector<vector<string>> flows = vector(n, vector<string>(m, "  "));
        flows[0][m-1] = "AP";
        flows[n-1][0] = "AP";

        queue<vector<int>> q;
        q.push({ 0, m-1 });

        unordered_set<string> memo;

        while(!q.empty()){
            vector<int> coord = q.front();
            q.pop();

            int r = coord[0];
            int c = coord[1];
            
            if(flows[r][c] != "AP"){
                if(r == 0 || c == 0)
                    flows[r][c][1] = 'P';
                if(r == n-1 || c == m-1)
                    flows[r][c][0] = 'A';

                if(r-1 >= 0 && heights[r][c] >= heights[r-1][c]){
                    flows[r][c][0] = (flows[r][c][0] == 'A') ? 'A' : flows[r-1][c][0];
                    flows[r][c][1] = (flows[r][c][1] == 'P') ? 'P' : flows[r-1][c][1];
                }

                if(c+1 < m && heights[r][c] >= heights[r][c+1]){
                    flows[r][c][0] = (flows[r][c][0] == 'A') ? 'A' : flows[r][c+1][0];
                    flows[r][c][1] = (flows[r][c][1] == 'P') ? 'P' : flows[r][c+1][1];
                }
            }

            //adding nodes
            if(c-1 >= 0)
                q.push({ r, c-1 });

            if(r+1 < n)
                q.push({ r+1, c });
        }

        q.push({ n-1, 0 });
        while(!q.empty()){
            vector<int> coord = q.front();
            q.pop();

            int r = coord[0];
            int c = coord[1];
            if(flows[r][c] != "AP"){
                if(r == 0 || c == 0)
                    flows[r][c][1] = 'P';
                if(r == n-1 || c == m-1)
                    flows[r][c][0] = 'A';

                if(r+1 < n && heights[r+1][c] <= heights[r][c]){
                    flows[r][c][0] = (flows[r][c][0] == 'A') ? 'A' : flows[r+1][c][0];
                    flows[r][c][1] = (flows[r][c][1] == 'P') ? 'P' : flows[r+1][c][1];
                }

                if(c-1 >= 0 && heights[r][c-1] <= heights[r][c]){
                    flows[r][c][0] = (flows[r][c][0] == 'A') ? 'A' : flows[r][c-1][0];
                    flows[r][c][1] = (flows[r][c][1] == 'P') ? 'P' : flows[r][c-1][1];
                }
            }

            //adding nodes
            if(c+1 < m)
                q.push({ r, c+1 });
            if(r-1 >= 0)
                q.push({ r-1, c });

            string key = to_string(r) + to_string(c);
            if(flows[r][c] == "AP" && memo.find(key) == memo.end()){
                pos.push_back({ r, c });

                memo.insert(key);
            }
        }

        return pos;
    }
};
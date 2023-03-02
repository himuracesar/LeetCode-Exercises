class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<map<int, int>> rowsmap(n);
        vector<map<int, int>> colsmap(n);
        vector<map<int, int>> matmap(n);

        for(auto i = 0; i < n; i++)
        {
            for(auto j = 0; j < m; j++)
            {
                int c = board[i][j] - '0';
                //cout << "c:: " << c << endl;
                if(c > 0 && c <= 9)
                {
                    if(rowsmap[i][c])
                        return false;

                    if(colsmap[j][c]) 
                        return false;  

                    if(matmap[i / 3 * 3 + j / 3][c])
                        return false;
                                           
                    rowsmap[i][c] = c;
                    colsmap[j][c] = c;
                    matmap[i / 3 * 3 + j / 3][c] = c;
                }
            }
        }

        return true;
    }
};
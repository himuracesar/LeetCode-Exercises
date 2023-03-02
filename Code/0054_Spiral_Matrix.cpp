class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size() == 0)
            return res;

        int n =  matrix.size();
        int m = matrix[0].size();

        int top = 0;
        int left = 0;
        int right = m - 1;
        int bottom = n - 1;
        int total = n * m;
        int count = 0;
        int row = 0;
        int col = 0;
        int directions[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };
        int inxdir = 0;

        //cout << right << " --- " << bottom << endl;
        while(count < total)
        {
            //cout << "ADD:: (" << row << "," << col << "):: "  << matrix[row][col] << endl;
            res.push_back(matrix[row][col]);
            count++;

            int _row = row + directions[inxdir][0];
            int _col = col + directions[inxdir][1];
            //cout << "CHECK:: (" << _row << "," << _col << ")" << endl;
            //cout << "top:: " << top << " left:: " << left << " right:: " << right << " bottom:: " << bottom << endl;
            if(_row > bottom || _row < top || _col < left || _col > right)
            {
                inxdir++;
                inxdir = (inxdir > 3) ? 0 : inxdir;

                switch(inxdir)
                {
                    case 0: left++;
                        break;
                    case 1: top++;
                        break;
                    case 2: right--;
                        break;
                    case 3: bottom--;
                        break;
                }

                //cout << ".:CAMBIO:: " << inxdir << endl;
            }

            row = row + directions[inxdir][0];
            col = col + directions[inxdir][1];

            //cout << "NEXT:: (" << row << "," << col << ")" << endl;
        }

        return res;
    }
};
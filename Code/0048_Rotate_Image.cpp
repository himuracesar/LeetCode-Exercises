class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int first = 0;
        int last = matrix.size()-1;
        int iDir = 0;

        vector<vector<int>> dirs = { {0,1},{1,0},{0,-1},{-1,0} };

        while(first < last){
            int step = last-first;
            for(auto i = first; i < last; i++){
                int lastRow = first;
                int lastCol = i;
                int aux = matrix[lastRow][lastCol];
                for(auto j = 0; j < 4; j++){
                    int row = dirs[iDir][0] * step + lastRow;
                    int col = dirs[iDir][1] * step + lastCol;

                    iDir = (iDir + 1 == dirs.size()) ? 0 : iDir + 1;

                    int spareRow = getSpare(first, last, row);
                    int spareCol = getSpare(first, last, col);

                    row = min(max(row, first), last);
                    col = min(max(col, first), last);

                    if(spareRow > 0) {
                        col += dirs[iDir][1] * spareRow;
                    } else if(spareCol > 0) {
                        row += dirs[iDir][0] * spareCol;
                    }
                    
                    int copy = matrix[row][col];
                    matrix[row][col] = aux;
                    aux = copy;

                    lastRow = row;
                    lastCol = col;
                }
            }

            first++;
            last--;
        }
    }

    int getSpare(int first, int last, int value){
        if(value < first){
            return first - value;
        } else if(value > last){
            return value - last;
        }

        return 0;
    }
};
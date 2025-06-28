class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> rc;

        for(auto i = 0; i < matrix.size(); i++){
            for(auto j = 0; j < matrix[0].size(); j++){
                if(matrix[i][j] == 0){
                    rc.push_back(i);
                    rc.push_back(j);
                }
            }
        }

        //rows
        for(auto i = 0; i < rc.size(); i += 2){
            for(auto j = 0; j < matrix[0].size(); j++){
                matrix[rc[i]][j] = 0;
            }
        }
        
        //columns
        for(auto i = 1; i < rc.size(); i += 2){
            for(auto j = 0; j < matrix.size(); j++){
                matrix[j][rc[i]] = 0;
            }
        }
    }
};
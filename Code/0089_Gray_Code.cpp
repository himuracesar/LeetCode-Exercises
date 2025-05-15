class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> code;
        vector<int> dir;

        int jump = 1;

        code.push_back(0);
        code.push_back(1);
        dir.push_back(1);

        for(auto i = 2; i <= n; i++){
            int powerBase = pow(2, i);
            int limit = powerBase - 1;
            jump *= 2;
            int m = powerBase - code.size();
            for(auto j = 0; j < m; j++){
                if(j == 0){
                    code.push_back(code[code.size() - 1] + jump);
                    dir.push_back(jump);
                } else {
                    int next = code[code.size() - 1] + dir[j - 1];
                    if(next > limit){
                        code.push_back(code[code.size() - 1] - dir[j - 1]);
                        dir.push_back(-dir[j - 1]);
                    } else {
                        code.push_back(next);
                        dir.push_back(dir[j - 1]);
                    }
                }
            }
        }

        return code;
    }
};
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        if(points.size() < 3)
            return 0;

        int boomerangs = 0;

        vector<vector<long>> memo(points.size(), vector<long>(points.size(), 0l));

        for(auto i = 0; i < points.size(); i++){
            map<long,int> founded;
            for(auto j = 0; j < points.size(); j++){
                if(i == j)
                    continue;
                
                if(memo[i][j] == 0.0f){
                    memo[i][j] = calculateDistance(points[i], points[j]);
                    memo[j][i] = memo[i][j];
                }

                if(founded.find(memo[i][j]) != founded.end()){
                    boomerangs += founded[memo[i][j]] * 2;

                    founded[memo[i][j]]++;
                }
                else{
                    founded[memo[i][j]] = 1;
                }
            }
        }

        return boomerangs;
    }

    long calculateDistance(vector<int>& p1, vector<int>& p2){
        long x = p2[0] - p1[0];
        long y = p2[1] - p1[1];

        return x * x + y * y;
    }
};
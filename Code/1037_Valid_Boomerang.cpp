class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        float m1 = calculatePendient(points[0][0], points[0][1], points[1][0], points[1][1]);
        float m2 = calculatePendient(points[0][0], points[0][1], points[2][0], points[2][1]);
        
        if(points[0][0] == points[1][0] && points[0][1] == points[1][1])
            return false;
        if(points[0][0] == points[2][0] && points[0][1] == points[2][1])
            return false;
        if(points[2][0] == points[1][0] && points[2][1] == points[1][1])
            return false;
        //cout << " m1:: " << m1 << " m2:: " << m2 << endl;
        return (m1 != m2);
    }

    float calculatePendient(int x1, int y1, int x2, int y2){
        float x = x2 - x1;
        if(x == 0.0f)
            return FLT_MAX;

        return (y2 - y1) / x;
    }
};
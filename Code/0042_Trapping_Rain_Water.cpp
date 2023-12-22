class Solution {
public:
    int trap(vector<int>& height) {
        int p1 = -1;
        int units = 0;
        int units_aux = 0;

        for(auto i = 0; i < height.size(); i++){
            if(p1 == -1 && height[i] > 0){
                p1 = i;
            } else if(p1 > -1){
                if(height[i] >= height[p1]){
                    units += units_aux;
                    units_aux = 0;
                    p1 = i;
                } else {
                    units_aux += height[p1] - height[i];
                }
            }
        }

        if(p1 < height.size() - 1){
            int end = p1 == -1 ? 0 : p1;
            units_aux = 0;
            p1 = -1;
            for(int i = height.size() - 1; i >= end; i--){
                //cout << "i:: " << i << "[]:: " << height[i] << endl;
                if(p1 == -1 && height[i] > 0)
                    p1 = i;
                else if(p1 > -1){
                    if(height[i] >= height[p1]){
                        units += units_aux;
                        units_aux = 0;
                        p1 = i;
                    } else {
                        units_aux += height[p1] - height[i];
                    }
                }
            }
        }

        return units;
    }
};
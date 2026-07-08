class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        vector<vector<long long>> painting;

        vector<long long> negColor(1e5 + 1, 0);
        vector<long long> posColor(1e5 + 1, 0);

        cout << segments.size() << endl;

        for(auto i = 0; i < segments.size(); i++){
            posColor[segments[i][0]] += segments[i][2];
            negColor[segments[i][1]] += segments[i][2];
        }

        vector<long long> paint = { 0, 0, 0 };
        for(auto i = 0; i < posColor.size(); i++){
            if(posColor[i] == 0 && negColor[i] == 0)
                continue;

            if(negColor[i] > 0){
                if(paint[0] == 0){
                    paint[0] = i;
                } else if(paint[1] == 0){
                    paint[1] = i;

                    painting.push_back(paint);

                    long long color = paint[2] - negColor[i];
                    if(color > 0)
                        paint = { i, 0, color};
                    else
                        paint = { 0, 0, 0};
                }
            }

            if(posColor[i] > 0){
                if(paint[0] == 0){
                    paint[0] = i;
                    paint[2] = posColor[i];
                } else if(paint[0] == i){
                    paint[2] += posColor[i];
                } else if(paint[1] == 0){
                    paint[1] = i;

                    painting.push_back(paint);

                    paint = { i, 0, paint[2] + posColor[i] };
                }
            }
        }

        return painting;
    }
};
class Solution {
public:
    int candy(vector<int>& ratings) {
        int numCandy = 0;
        vector<int> bagCandy;
        vector<vector<int>> subarrays;

        enum DIRECTION {
            NONE,
            UP,
            DOWN
        };

        for(auto i = 0; i < ratings.size(); i++)
            bagCandy.push_back(0);

        DIRECTION dir = NONE;

        vector<int> range;
        range.push_back(0); //start
        range.push_back(0); //end
        for(auto i = 1; i < ratings.size(); i++){
            if(ratings[i] == ratings[i-1]){
                subarrays.push_back(range);

                range[0] = i;
                range[1] = i;
                
                dir = NONE;
            } else if(ratings[i] > ratings[i-1]){
                if(dir == NONE || dir == DOWN){
                    subarrays.push_back(range);

                    range[0] = i-1;
                    range[1] = i;

                    dir = UP;
                } else {
                    range[1]++;
                }
            } else if(ratings[i] < ratings[i-1]){
                if(dir == NONE || dir == UP){
                    subarrays.push_back(range);
                    range[0] = i;
                    range[1] = i-1;
                } else {
                    range[0]++;
                }
                dir = DOWN;
            }
        }

        subarrays.push_back(range);

        for(auto i = 0; i < subarrays.size(); i++){
            numCandy = 1;
            //cout << "start:: " << subarrays[i][0] << " end:: " << subarrays[i][1] << endl;
            if(subarrays[i][0] <= subarrays[i][1]){
                bagCandy[subarrays[i][0]] = numCandy++;
                for(auto j = subarrays[i][0] + 1; j <= subarrays[i][1]; j++){
                    if(bagCandy[j] <= bagCandy[j-1])
                        bagCandy[j] = numCandy++;
                    else
                        break;
                }
            } else if(subarrays[i][0] > subarrays[i][1]){
                bagCandy[subarrays[i][0]] = numCandy++;
                for(auto j = subarrays[i][0] -  1; j >= subarrays[i][1]; j--){
                    if(bagCandy[j] <= bagCandy[j+1])
                        bagCandy[j] = numCandy++;
                    else
                        break;
                }
            }
        }

        numCandy = 0;
        for(auto i = 0; i < bagCandy.size(); i++){
            //cout << "bag[" << i << "]:: " << bagCandy[i] << endl;
            numCandy += bagCandy[i];
        }

        return numCandy;
    }
};
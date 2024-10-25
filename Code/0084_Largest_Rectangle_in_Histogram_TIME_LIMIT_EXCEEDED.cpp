/**
* Constraints:
*
* 1 <= heights.length <= 10^5
* 0 <= heights[i] <= 10^4
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<vector<int>> keeps;
        int last = INT_MIN;
        int counter = 0;
        int maxarea = 0;
        for(auto i = 0; i < heights.size(); i++){
            int index = -1;
            //cout << "--------------------" << endl;
            for(auto j = 0; j < keeps.size(); j++){
                //cout << keeps[j][0] << " | " << keeps[j][1] << endl;
                if(keeps[j][1] == 0 && keeps[j][0] != heights[i])
                    continue;
                if(keeps[j][0] == heights[i]){
                    index = j;
                    counter = max(counter, keeps[j][1]);
                } else if(keeps[j][0] > heights[i]){
                    counter = max(counter, keeps[j][1]);
                    keeps[j][1] = 0;
                } else {
                    //counter = max(counter, keeps[j][1]);
                    keeps[j][1]++;

                    maxarea = max(maxarea, keeps[j][0] * keeps[j][1]);
                }
            }

            if(index == -1){
                vector<int> v;
                v.push_back(heights[i]);
                v.push_back(counter + 1);
                keeps.push_back(v);

                maxarea = max(maxarea, heights[i] * keeps[keeps.size() - 1][1]);
            } else { 
                keeps[index][1] = counter + 1;
                maxarea = max(maxarea, keeps[index][0] * keeps[index][1]);
            }

            counter = 0;
            index = -1;
        }

        return maxarea;
    }
};
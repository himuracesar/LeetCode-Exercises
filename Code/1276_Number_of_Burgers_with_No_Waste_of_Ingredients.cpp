class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> burgers;

        if(tomatoSlices % 2 != 0)
            return burgers;

        int jumbos = (tomatoSlices - 2 * cheeseSlices) / 2;
        int small = cheeseSlices - jumbos;

        if(jumbos >= 0 && small >= 0){
            burgers.push_back(jumbos);
            burgers.push_back(small);
        }

        return burgers;
    }
};
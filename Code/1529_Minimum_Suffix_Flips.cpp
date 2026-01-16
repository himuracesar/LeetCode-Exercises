class Solution {
public:
    int minFlips(string target) {
        int flips = 2;
        int turns = 0;

        for(auto i = 0; i < target.length(); i++){
            if(target[i] - '1' == 0 && flips % 2 == 0){
                flips++;
            } else if(target[i] - '0' == 0 && flips % 2 > 0){
                flips++;
            }
        }

        return flips - 2;
    }
};
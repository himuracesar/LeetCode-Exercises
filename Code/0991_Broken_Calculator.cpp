class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int moves = 0;
        
        while(target > startValue){
            if(target % 2 > 0){
                target = ceil(target / 2.0f);
                moves += 2;
            } else {
                target /= 2;
                moves++;
            }
        }

        moves += startValue - target;
        
        return moves;
    }
};
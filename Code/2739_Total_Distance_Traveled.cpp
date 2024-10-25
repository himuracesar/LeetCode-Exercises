class Solution {
public:
    int distanceTraveled(int mainTank, int additionalTank) {
        int km = 0;

        while(mainTank > 0){
            if(mainTank < 5){
                km += mainTank * 10;
                mainTank = 0;
            } else {
                int grp = mainTank / 5;
                mainTank = mainTank % 5;
                km += grp * 5 * 10;

                if(grp > 0 && additionalTank > 0){
                    mainTank += min(grp, additionalTank);
                    additionalTank = (additionalTank - grp < 0) ? 0 : additionalTank - grp;
                }
            }
        }

        return km;
    }
};
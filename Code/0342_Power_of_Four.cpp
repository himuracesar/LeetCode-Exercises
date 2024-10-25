class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1)
            return true;
        if(n == 0)
            return 0;

        int res = 0;
        while(res == 0){
            res = n % 4;
            n = n / 4;

            if(res == 0 && n == 1)
                return true;
        }

        return false;
    }
};
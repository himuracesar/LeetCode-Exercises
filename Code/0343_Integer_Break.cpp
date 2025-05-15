class Solution {
public:
    int integerBreak(int n) {
        if(n == 2 || n == 3)
            return n - 1;

        int exp = n / 3;
        int mod = n % 3;

        switch(mod){
            case 0: return pow(3, exp);
            case 1: 
                exp -= 1;
                return pow(3, exp) * 4;
            case 2: return pow(3, exp) * 2;
        }

        return 0;
    }
};
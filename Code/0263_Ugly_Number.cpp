class Solution {
public:
    bool isUgly(int n) {
        int primes[] = {2, 3, 5};

        int prevn = n;
        while(n != 1){
            prevn = n;
            for(auto i = 0; i < 3; i++){
                if(n % primes[i] == 0){
                    n = n / primes[i];
                }
            }

            if(prevn == n)
                return false;
        }

        return true;
    }
};
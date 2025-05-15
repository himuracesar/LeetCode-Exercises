class Solution {
public:
    int lastRemaining(int n) {
        int init = 1;
        int gap = 1;
        int dir = 1; //1 right -- -1 left

        while(n > 1){
            if(dir == 1 || (dir == -1 && n % 2 != 0))
                init += gap;

            dir = -dir;

            gap *= 2;

            int del = ceil(n / 2.0f);
            n = n - del;

            //cout << "n:: " << n << " init:: " << init << " gap:: " << gap << endl;
        }

        return init;
    }
};
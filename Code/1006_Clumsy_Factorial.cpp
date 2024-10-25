class Solution {
public:
    int clumsy(int n) {
        int op1 = 0;
        int op2 = 0;
        int count = 1;
        int ac = n;

        for(auto i = n - 1; i > 0; i--){
            switch(count){
                case 1:
                    ac = ac * i;
                break;
                
                case 2:
                    ac = ac / i; 
                break;

                case 3:
                    ac += i;
                    op1 += ac; 
                    ac = 0;
                break;

                case 4:
                    ac = -i;
                    count = 0;
                break;
            }

            count++;
            //cout << "ac:: " << ac << endl;
        }

        op1 += ac;

        return op1;
    }
};
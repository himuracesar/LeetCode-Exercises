class Solution {
public:
    int mySqrt(int x) {
        int root = 1;
        long res = 0;

        while(res < x){
            res = (long)root * (long)root;
            if(res > x)
                break;
            
            root++;
        }

        return root - 1;
    }
};
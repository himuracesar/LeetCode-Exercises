class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;

        double exp = log2(n);
        double diff = exp - (long)exp;
        
        if(diff == 0.0)
            return true;

       return false; 
    }
};
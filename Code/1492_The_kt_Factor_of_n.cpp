class Solution {
public:
    int kthFactor(int n, int k) {
        if(k == 1)
            return 1;

        int kth = 1;
        for(auto i = 2; i <= n / 2; i++){
            if(n % i == 0){
                if(++kth == k)
                    return i;
            }
            //cout << kth << " -- " << i << endl;
        }

        if(++kth == k)
            return n;

        return -1;
    }
};

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long pairs = 0;

        int odds = ceil(m / 2.0f);
        int evens = m - odds;

        //cout << "e:: " << evens << " o:: " << odds << endl;
        for(auto i = 1; i <= n; i++){
            if(i % 2 == 0)
                pairs += odds;
            else
                pairs += evens;
        }

        return pairs;
    }
};
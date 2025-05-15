class Solution {
public:
    int nthUglyNumber(int n) {
        int primes[] = {2,3,5};

        priority_queue<int, vector<int>, greater<int>> pq;
        pq.push(primes[0]);
        pq.push(primes[1]);
        pq.push(primes[2]);

        map<int,int> cache;

        int index = 1;

        int currentVal = 1;

        while(index < n){
            index++;

            currentVal = pq.top();
            pq.pop();

            for(auto i = 0; i < 3; i++){
                long Lval = (long)primes[i] * (long)currentVal;
                int val = (Lval >= INT_MAX) ? 0 : (int)Lval;
                if(val > 0 && cache.find(val) == cache.end()){
                    cache[val] = val;
                    pq.push(val);
                }
            }
        }
        
        return currentVal;
    }
};
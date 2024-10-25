class Solution {
public:
    bool isHappy(int n) {
        queue<int> q;
        map<int, int> cache;

        q.push(n);
        while(!q.empty()){
            string sn = to_string(q.front());
            int sumsq = 0;
            for(auto i = 0; i < sn.length(); i++){
                int isn = sn[i] - '0';
                sumsq += isn * isn;
            }

            if(sumsq == 1)
                return true;
            if(cache.find(sumsq) != cache.end())
                return false;
            else
                cache[sumsq] = sumsq; 

            q.pop();
            q.push(sumsq);
        }

        return false;
    }
};
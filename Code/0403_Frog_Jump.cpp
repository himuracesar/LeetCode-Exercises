class Solution {
public:
    bool canCross(vector<int>& stones) {
        map<int,int> hmStones;
        map<int,map<int,int>> cache;

        queue<int> qStones;
        queue<int> qSteps;

        for(auto i = 0; i < stones.size(); i++)
            hmStones[stones[i]] = i;

        qStones.push(stones[0]);
        qSteps.push(1);
        while(!qStones.empty()){
            
            for(auto i = -1; i < 2; i++){
                int step = qSteps.front() + i;
                int pos = qStones.front() + step;

                if(step <= 0 || (qStones.front() == 0 && step != 1))
                    continue;

                if(pos == stones[stones.size() - 1])
                    return true;

                if(hmStones.find(pos) != hmStones.end()){
                    if(cache.find(pos) == cache.end() || cache[pos][step] == 0){
                        qStones.push(pos);
                        qSteps.push(step);
                        cache[pos][step] = step;
                    }
                }
            }

            qStones.pop();
            qSteps.pop();
        }

        return false;
    }
};
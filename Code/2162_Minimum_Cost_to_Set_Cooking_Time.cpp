class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        vector<string> times;

        int mins = targetSeconds / 60;
        int secs = targetSeconds % 60;

        string time = "";
        
        if(mins < 100){
            if(mins > 0)
                time = to_string(mins);

            if(secs < 10 && mins > 0)
                time += "0";

            time += to_string(secs);

            times.push_back(time);
        }

        if(mins > 0 && secs + 60 <= 99){
            time = "";
            if(mins - 1 > 0)
                time += to_string(mins - 1);
            
            time += to_string(secs + 60);
            times.push_back(time);
        }

        int nextNum = startAt;
        int cost = 0;
        int minCost = INT_MAX;
        for(auto i = 0; i < times.size(); i++){
            string t = times[i];
            //cout << "time:: " << t << endl;
            for(auto j = 0; j < t.length(); j++){
                int c = t[j] - '0';
                //cout << "c:: " << c << endl;
                if(nextNum != c){
                    cost += moveCost;
                }
                cost += pushCost;
                nextNum = c;
            }
            //cout << "cost:: " << cost << endl;
            minCost = min(minCost, cost);
            //cout << "minCost:: " << minCost << endl;
            cost = 0;
            nextNum = startAt;
        }

        return minCost;
    }
};
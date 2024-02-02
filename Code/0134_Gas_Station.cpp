class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> totals;

        for(auto i = 0; i < gas.size(); i++){
            totals.push_back(gas[i] - cost[i]);
        }

        int sumTotal = 0;
        int index = -1;
        int sum = 0;
        for(auto i = 0; i < totals.size(); i++){
            sumTotal += totals[i];
            sum += totals[i];
            index = (index == -1) ? i : index;
            if(sum < 0){
                index = -1;
                sum = 0;
            }
        }

        index = (sum < 0) ? -1 : index;

        if(sumTotal < 0)
            return -1;

        return index;
    }
};
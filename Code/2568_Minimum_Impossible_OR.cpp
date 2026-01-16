class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        set<int> powers;

        for(auto i = 0; i < nums.size(); i++){
            double exp = log2(nums[i]);
            int iexp = exp;

            if(exp - iexp == 0.00){
                if(powers.find(nums[i]) == powers.end()){
                    powers.insert(nums[i]);
                    pq.push(nums[i]);
                }
                
            }
        }

        int power = 1;
        while(!pq.empty()){
            //cout << pq.top() << endl;
            if(pq.top() != power)
                return power;
            
            pq.pop();
            power *= 2;
        }

        return power;
    }
};
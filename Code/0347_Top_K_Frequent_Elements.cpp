class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> topK;
        priority_queue<vector<int>> pq;

        map<int, int> freqs;
        for(auto i = 0; i < nums.size(); i++){
            freqs[nums[i]]++;
        }

        for(pair<int, int> p : freqs){
            pq.push({ p.second, p.first });
        }

        for(auto i = 0; i < k; i++){
            topK.push_back(pq.top()[1]);
            pq.pop();
        }

        return topK;
    }
};
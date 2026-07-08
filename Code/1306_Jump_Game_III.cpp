class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> cache(arr.size(), 0);

        queue<int> q;
        q.push(start);

        while(!q.empty()){
            int index = q.front();
            q.pop();

            if(arr[index] == 0)
                return true;

            if(cache[index] == 1)
                continue;

            cache[index] = 1;

            int indexp = index + arr[index];
            if(indexp < arr.size() && cache[indexp] == 0)
                q.push(indexp);
            
            int indexm = index - arr[index];
            if(indexm >= 0 && cache[indexm] == 0)
                q.push(indexm);
        }

        return false;
    }
};
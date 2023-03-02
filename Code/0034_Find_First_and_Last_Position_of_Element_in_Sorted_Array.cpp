class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;

        if(nums.size() > 0)
        {
            res.push_back(INT_MAX);
            res.push_back(INT_MIN);
        }
        else
        {
            res.push_back(-1);
            res.push_back(-1);

            return res;
        }

        map<string, string> it;

        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;

        string lastIt = to_string(start) + "-" + to_string(end);
        while(it.find(lastIt) == it.end() && start <= end)
        {
            it[lastIt] = lastIt;

            mid = (start + end) / 2;
            if(nums[start] == target)
                res[0] = min(res[0], start);

            if(nums[end] == target)
                res[1] = max(res[1], end);

            //cout << "mid:: " << mid << endl;
            if(nums[mid] == target)
            {
                res[0] = min(res[0], mid);
                res[1] = max(res[1], mid);

                start = (res[0] - 1 < 0) ? 0 : res[0] - 1;
                end = (res[1] + 1 > nums.size() - 1) ? nums.size() - 1 : res[1] + 1; 
            }
            else if(nums[mid] > target)
                end = mid - 1;
            else
                start  = mid + 1;

            lastIt = to_string(start) + "-" + to_string(end);
        }

        if(res[0] == INT_MAX)
        {
            res[0] = -1;
            res[1] = -1;
        }

        return res;
    }
};
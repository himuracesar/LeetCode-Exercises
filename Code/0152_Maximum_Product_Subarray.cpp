class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int subarrs[2] = {INT_MIN, INT_MIN};

        vector<int> maxheap;
        make_heap(maxheap.begin(), maxheap.end());

        maxheap.push_back(INT_MIN);
        push_heap(maxheap.begin(), maxheap.end());

        if(nums.size() == 1)
            return nums[0];

        bool firstSign = false;

        int total = INT_MIN;
        int subTotal = INT_MIN;
        for(auto i = 0; i < nums.size(); i++){
            total = (total == INT_MIN) ? nums[i] : total * nums[i];

            if(nums[i] == 0){
                maxheap.push_back(max(subTotal, max(subarrs[0], subarrs[1])));
                push_heap(maxheap.begin(), maxheap.end());

                subTotal = INT_MIN;
                subarrs[0] = INT_MIN;
                subarrs[1] = INT_MIN;
                firstSign = false;

                continue;
            }

            if(nums[i] < 0)
                subarrs[0] = max(subarrs[0], subTotal);

            subTotal = (subTotal == INT_MIN) ? nums[i] : subTotal * nums[i];
            
            if(firstSign)
                subarrs[1] = (subarrs[1] == INT_MIN) ? nums[i] : subarrs[1] * nums[i]; 

            if(!firstSign && nums[i] < 0)
                firstSign = true;
        }

        int maxP = max(subarrs[0], subarrs[1]);
        maxP = max(maxP, total);
        maxP = max(maxP, subTotal);

        return max(maxheap.front(), maxP);
    }
};
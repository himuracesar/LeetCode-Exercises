class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int pStart = 0;
        int pEnd = 0;

        long long total = nums[pStart];
        long long length = 1;
        long long numSubarrays = 0;

        bool add = true;

        if(nums[pStart] < k){
            numSubarrays = 1;
        }

        while(pStart < nums.size() - 1 || pEnd < nums.size() - 1){
            if(!add && pStart == pEnd)
                add = true;

            if(add){
                pEnd++;

                if(pEnd == nums.size())
                    break;

                length++;
                total += nums[pEnd];
                numSubarrays = (nums[pEnd] < k) ? numSubarrays + 1 : numSubarrays;
            } else {
                length--;
                total -= nums[pStart];
                pStart++;
            }

            if(total * length < k){
                numSubarrays += pEnd - pStart;

                add = true;
            } else {
                add = false;
            }

            //cout << "start:: " << pStart << " end:: " << pEnd << " sb:: " << numSubarrays << endl;
        }

        return numSubarrays;
        
    }
};
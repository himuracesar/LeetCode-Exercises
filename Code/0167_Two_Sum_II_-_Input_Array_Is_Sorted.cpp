class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(auto i = 0; i < numbers.size(); i++){
            int searching = target - numbers[i];
            int start = 0;
            int end = numbers.size()-1;
            int mid = 0;
            while(start <= end){
                mid = (start + end) / 2;
                if(numbers[mid] == searching){
                    if(mid == i)
                        mid = (mid-1 >= 0 && numbers[mid-1] == searching) ? mid-1 : mid+1;

                    return {i+1, mid+1};
                } else if(numbers[mid] > searching){
                    end = mid-1;
                } else {
                    start = mid+1;
                }
            }
        }

        return {0,0};
    }
};
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1])
            i--;

        if(i > -1){
            int ceil = i + 1;
            int j = ceil;

            while(j < nums.size()){
                if(nums[j] > nums[i] && nums[j] < nums[ceil])
                    ceil = j;

                j++;
            }

            swap(nums, i, ceil);
            i++;
            j = nums.size() - 1;
            QuickSort(nums, i, j);
        } else {
            QuickSort(nums, 0, nums.size() - 1);
        }
    }

    void swap(vector<int>& nums, int index1, int index2){
        int aux = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = aux;
    }

    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[end];
        int partitionIndex = start;
        for(auto i = start; i < end; i++){
            if(nums[i] <= pivot){
                swap(nums, i, partitionIndex);
                partitionIndex++;
            }
        }

        swap(nums, partitionIndex, end);

        return partitionIndex;
    }

    void QuickSort(vector<int>& nums, int start, int end){
        if(start < end){
            int partitionIndex = partition(nums, start, end);
            QuickSort(nums, start, partitionIndex - 1);
            QuickSort(nums, partitionIndex + 1, end);
        }
    }
};
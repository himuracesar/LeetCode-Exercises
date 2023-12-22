class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;

        QuickSort(nums, 0, nums.size() - 1);
        
        while(true){
            out.push_back(nums);
            int i = nums.size() - 2;
            while(i >= 0 && nums[i] >= nums[i + 1])
                i--;

            if(i == -1)
                break;

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
        }

        return out;
    }

    void swap(vector<int>& nums, int inx1, int inx2){
        int aux = nums[inx1];
        nums[inx1] = nums[inx2];
        nums[inx2] = aux;
    }

    int Partition(vector<int>& nums, int start, int end){
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
            int partitionIndex = Partition(nums, start, end);
            QuickSort(nums, start, partitionIndex - 1);
            QuickSort(nums, partitionIndex + 1, end);
        }
    }
};
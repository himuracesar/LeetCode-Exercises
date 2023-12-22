class Solution {
public:
    int maxCoins(vector<int>& piles) {
        MergeSort(piles);

        int iBob = 0;
        int iMine = piles.size() - 2;

        int numCoins = 0;

        while(iBob < iMine){
            numCoins += piles[iMine];
            iMine -= 2;
            iBob++;
        }

        return numCoins;
    }

    void Merge(vector<int>& left, vector<int>& right, vector<int>& arr){
        int nleft = left.size();
        int nright = right.size();
        int i = 0;
        int j = 0;
        int k = 0;

        while(i < nleft && j < nright){
            if(left[i] <= right[j]){
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }

            k++;
        }

        while(i < nleft){
            arr[k] = left[i];
            k++;
            i++;
        }

        while(j < nright){
            arr[k] = right[j];
            j++;
            k++;
        }
    }

    void MergeSort(vector<int>& arr){
        int n = arr.size();
        if(n < 2)
            return;

        int mid = n / 2;
        vector<int> left;
        vector<int> right;

        for(auto i = 0; i < mid; i++)
            left.push_back(arr[i]);
        for(auto i = mid; i < n; i++)
            right.push_back(arr[i]);

        MergeSort(left);
        MergeSort(right);
        Merge(left, right, arr);
    }
};
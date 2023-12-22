class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(auto i = 1; i <= n; i++)
            str += to_string(i);

        int i = n - 2;
        int numPermutation = 1;

        while(numPermutation < k){
          numPermutation++;
          int i = n - 2;
          while(i >= 0 && str[i] >= str[i + 1])
              i--;

          if(i == -1)
              return nullptr;

          int ceil = i + 1;
          int j = ceil;

          while(j < n){
              if(str[j] > str[i] && str[j] < str[ceil])
                  ceil = j;

              j++;
          }

          str = swap(str, i, ceil);

          i++;
          j = n - 1;
          QuickSort(str, i, j);
        }

        return str;
    }

    string swap(string& s, int inx1, int inx2){
      char aux = s[inx1];
      s[inx1] = s[inx2];
      s[inx2] = aux;

      return s;
    }

    int Partition(string& str, int start, int end){
        int pivot = str[end];
        int partitionIndex = start;
        for(auto i = start; i < end; i++){
            if(str[i] <= pivot){
                swap(str, i, partitionIndex);
                partitionIndex++;
            }
        }

        swap(str, partitionIndex, end);

        return partitionIndex;
    }

    void QuickSort(string& str, int start, int end){
        if(start < end){
            int partitionIndex = Partition(str, start, end);
            QuickSort(str, start, partitionIndex - 1);
            QuickSort(str, partitionIndex + 1, end);
        }
    }
};
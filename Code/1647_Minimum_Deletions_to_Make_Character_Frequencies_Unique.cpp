class Solution {
public:
    int minDeletions(string s) {
        map<char,int> charFrequency;
        for(auto i = 0; i < s.length(); i++){
            if(charFrequency.find(s[i]) != charFrequency.end()){
                charFrequency[s[i]]++;
            } else {
                charFrequency[s[i]] = 1;
            }
        }

        vector<int> freqs;
        for(auto cf : charFrequency)
            freqs.push_back(cf.second);
        
        MergeSort(freqs);

        int last = 0;
        int deletes = 0;

        /*for(auto i = 0; i < freqs.size(); i++)
            cout << freqs[i] << endl;*/

        for(auto i = 1; i < freqs.size(); i++){
           if(freqs[i] >= freqs[i - 1]){
                int d = freqs[i] - freqs[i - 1];

                if(freqs[i - 1] > 0)
                    d++;

                freqs[i] -= d;
                deletes += d;
           }
        }

        return deletes;
    }

    void Merge(vector<int>& left, vector<int>& right, vector<int>& arr){
        int nleft = left.size();
        int nright = right.size();
        int i = 0;
        int j = 0;
        int k = 0;
        while(i < nleft && j < nright){
            if(left[i] >= right[j]){
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
            k++;
            j++;
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
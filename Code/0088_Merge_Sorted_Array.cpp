class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int _m = 0;
        int _n = 0;
        
        queue<int> q;
        
        while(_m < m || _n < n)
        {
            //cout << "_m:: " << _m << " _n:: " << _n << endl;
            if(_m == m)
            {
                q.push(nums2[_n]);
                _n++;
            }
            else if(_n == n)
            {
                q.push(nums1[_m]);
                _m++;
            }
            else if(nums1[_m] <= nums2[_n])
            {
                q.push(nums1[_m]);
                _m++;
            }
            else if(nums1[_m] > nums2[_n])
            {
                q.push(nums2[_n]);
                _n++;
            }
        }
        
        int i = 0;
        while(!q.empty())
        {
            nums1[i++] = q.front();
            q.pop();
        }
    }
};
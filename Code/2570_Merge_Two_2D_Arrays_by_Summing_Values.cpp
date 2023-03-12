class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int i = 0;
        int j = 0;

        vector<vector<int>> mergearr;

        while(i < nums1.size() || j < nums2.size())
        {
            if(i == nums1.size())
                mergearr.push_back(nums2[j++]);
            else if(j == nums2.size())
                mergearr.push_back(nums1[i++]);
            else
            {
                if(nums1[i][0] < nums2[j][0])
                    mergearr.push_back(nums1[i++]);
                else if(nums1[i][0] > nums2[j][0])
                    mergearr.push_back(nums2[j++]);
                else if(nums1[i][0] == nums2[j][0])
                {
                    mergearr.push_back(nums1[i]);
                    mergearr[mergearr.size() - 1][1] += nums2[j][1];
                    i++;
                    j++;
                }
            }
        }

        return mergearr;
    }
};
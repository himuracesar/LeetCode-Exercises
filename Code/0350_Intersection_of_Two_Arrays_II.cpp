class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;
        unordered_map<int, int> um;

        for(auto i = 0; i < nums1.size(); i++)
        {
            //cout << "--- " << um[nums1[i]] << endl;
            if(!um[nums1[i]])
            {
                um[nums1[i]] = 1; 
            }
            else
            {
                um[nums1[i]] = um[nums1[i]] + 1;
            }

            //cout << nums1[i] << ":: " << um[nums1[i]] << endl;
        }

        for(auto i = 0; i < nums2.size(); i++)
        {
            if(um[nums2[i]] > 0)
            {
                um[nums2[i]] = um[nums2[i]] - 1;
                nums.push_back(nums2[i]);
            }
            //cout << nums2[i] << ":: " << um[nums2[i]] << endl;
        }

        return nums;
    }
};
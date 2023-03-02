class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = "";
        int countPrefix = 2;
        
        map<string, int> hm;
        
        if(strs.size() == 1)
            return strs[0];
        
        for(auto i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            string eval = "";
            
            for(auto j = 0; j < s.length(); j++)
            {
                eval += s.at(j);
                
                if(hm[eval])
                {
                    hm[eval] = hm[eval] + 1;
                }
                else
                {
                    hm[eval] = 1;
                }
                
                if(hm[eval] >= countPrefix)
                {
                    countPrefix = hm[eval];
                    prefix = eval;
                }
            }
        }
        
        if(countPrefix == strs.size())
            return prefix;
        else
            return "";
    }
};
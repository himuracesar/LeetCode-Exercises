class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long totalC = 0;

        for(auto i = 0; i < s.length(); i++){
            if(s[i] == c)
                totalC++;
        }

        long long ans = totalC * (totalC + 1) / 2;

        return ans;
    }
};
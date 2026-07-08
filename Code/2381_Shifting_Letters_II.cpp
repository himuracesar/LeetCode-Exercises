class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        const int ALPHABET_SIZE = 26;

        vector<int> changes(s.length(), 0);

        for(auto i = 0; i < shifts.size(); i++){
            int val = shifts[i][2] == 0 ? -1 : 1;
            changes[shifts[i][0]] += val;
            if(shifts[i][1] + 1 < s.length())
                changes[shifts[i][1] + 1] += -val;
        }

        int carry = 0;
        for(auto i = 0; i < s.length(); i++){
            carry += changes[i];
            int l = (s[i] - 'a' + carry) % ALPHABET_SIZE;
            
            if(l < 0)
                s[i] = 'z' + l + 1;
            else
                s[i] = 'a' + l;
        }

        return s;
    }
};
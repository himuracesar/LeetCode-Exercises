class Solution {
public:
    int numDecodings(string s) {
        const int TOTAL_LETTERS = 26;

        vector<int> ways;
        for(auto i = 0; i < s.length(); i++){
            ways.push_back(0);
        }

        ways[s.length() - 1] = (s[s.length() - 1] - '0' == 0) ? 0 : 1;

        for(int i = s.length() - 2; i >= 0; i--){
            int digit1 = s[i] - '0';
            int digit2 = s[i + 1] - '0';

            ways[i] = ways[i + 1];
            if(digit1 == 0)
                ways[i] = 0;
            else {
                int combined = digit1 * 10 + digit2;
                if(combined <= TOTAL_LETTERS)
                    if(i + 2 == s.length()){
                        ways[i]++;
                    }
                    else if(i + 2 < s.length())
                        ways[i] += ways[i + 2];
            }
        }

        return ways[0];
    }
};
class Solution {
public:
    string replaceDigits(string s) {
        int n = s.length();
        int current = 0;

        for(int i = 0; i < n; i++){
            if(i % 2 == 0)
                current = s[i];
            else {
                int digit = s[i] - '0';
                s[i] = current + digit;
            }
        }

        return s;
    }
};
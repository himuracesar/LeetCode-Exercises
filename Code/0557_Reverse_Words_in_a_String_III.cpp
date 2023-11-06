class Solution {
public:
    string reverseWords(string s) {
        string reverse = "";
        int start = 0;
        int end = -1;
        for(auto i = 0; i < s.length(); i++){
            if(s[i] == ' '){
                int start = i - 1;
                reverse += ReverseString(start, end, s) + " ";
                end = -1;
            } else {
                if(end == -1)
                    end = i;
            }
        }
        reverse += ReverseString(s.length() - 1, end, s);

        return reverse;
    }

    string ReverseString(int start, int end, string& s){
        string reverse = "";
        for(auto j = start; j >= end; j--)
            reverse += s[j];
        
        return reverse;
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> letters;

        int length = s.length();

        for(auto i = 0; i < s.length(); i++){
            if(letters.find(s[i]) == letters.end())
                letters[s[i]] = 1;
            else
                letters[s[i]]++;
        }

        for(auto i = 0; i < t.length(); i++){
            if(letters.find(t[i]) == letters.end())
                return false;

            letters[t[i]]--;
            length--;
            if(letters[t[i]] < 0 || length < 0)
                return false;
        }

        return (length == 0);
    }
};
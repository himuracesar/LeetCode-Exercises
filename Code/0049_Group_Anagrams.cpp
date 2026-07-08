class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams;

        map<map<char,int>, int> hash;

        for(string s : strs){
            map<char, int> h;
            for(auto i = 0; i < s.length(); i++){
                if(h.find(s[i]) != h.end())
                    h[s[i]]++;
                else
                    h[s[i]] = 1;
            }

            if(hash.find(h) != hash.end()){
                int index = hash[h];
                anagrams[index].push_back(s);
            } else {
                anagrams.push_back({ s });
                hash[h] = anagrams.size() - 1;
            }
        }
        
        return anagrams;
    }
};
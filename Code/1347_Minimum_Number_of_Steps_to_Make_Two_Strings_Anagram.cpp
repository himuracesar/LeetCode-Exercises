class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int> ms;
        map<char,int> mt;

        for(auto i = 0; i < s.length(); i++){
            ms[s[i]]++;
            mt[t[i]]++;
        }

        int steps = 0;
        for(auto i = ms.begin(); i != ms.end(); i ++){
            int res = i->second - mt[i->first];
            if(res > 0)
                steps += res;
        }

        return steps;
    }
};
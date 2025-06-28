class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<int, vector<int>> intervals;
        map<string, int> memo;

        for(auto i = 0; i < wordDict.size(); i++){
            string word = wordDict[i];

            int j = 0;
            int length = word.length();
            int difLenghts = s.length() - length;
            while(j <= difLenghts){
                if(word == s.substr(j, length)){
                    intervals[j].push_back(j);
                    intervals[j].push_back(j + length - 1);
                }

                j++;
            }
        }

        return breaking(intervals, memo, 0, s.length() - 1);
    }

    bool breaking(map<int, vector<int>>& intervals, map<string, int>& memo, int key, int posFinal){
        vector<int> iv = intervals[key];
        for(auto i = 0; i < iv.size(); i += 2){
            string k = to_string(iv[i]) + ":" + to_string(iv[i + 1]);

            if(iv[i + 1] == posFinal)
                return true;

            if(memo.find(k) == memo.end()){
                memo[k] = 1;
                if(breaking(intervals, memo, iv[i + 1] + 1, posFinal))
                    return true;
            }
        }

        return false;
    }
};
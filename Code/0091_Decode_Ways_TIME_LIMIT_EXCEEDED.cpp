class Solution {
public:
    int numDecodings(string s) {
        map<int, int> cache;

        return numDecodings(s, 0, cache);
    }

    int numDecodings(string& s, int index, map<int, int> cache){
        const int TOTAL_LETTERS = 26;
        int num1 = s[index] - '0';
        if(num1 > 0){
            if(index + 1 == s.length()){
                cache[index] = 1;
            } else if(cache.find(index + 1) == cache.end())
                cache[index] = numDecodings(s, index + 1, cache);
            else
                cache[index] = cache[index + 1];

            int num2 = s[index + 1] - '0';
            int numCombined = num1 * 10 + num2;
            if(numCombined <= TOTAL_LETTERS){
                if(index + 2 == s.length())
                    cache[index] += 1;
                else if(index + 2 < s.length())
                    if(cache.find(index + 2) == cache.end())
                        cache[index] += numDecodings(s, index + 2, cache);
                    else
                        cache[index] += cache[index + 2];
            }

            return cache[index];
        }

        return 0;
    }
};
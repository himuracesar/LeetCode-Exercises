class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char, vector<char>, greater<char>> pq;
        vector<int> indexVowels;

        char vowels[10] = {'a','e','i','o','u','A','E','I','O','U'};

        for(auto i = 0; i < s.length(); i++){
            for(auto j = 0; j < 10; j++){
                if((vowels[j] - s[i]) == 0){
                    indexVowels.push_back(i);
                    pq.push(s[i]);
                    break;
                }
            }
        }

        for(auto i = 0; i < indexVowels.size(); i++){
            s[indexVowels[i]] = pq.top();
            pq.pop();
        }

        return s;
    }
};
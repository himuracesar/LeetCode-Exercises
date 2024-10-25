class Solution {
public:
    char kthCharacter(int k) {
        vector<char> str{'0','a'};

        while(str.size() <= k){
            int size = str.size();
            for(auto i = 1; i < size; i++){
                char c = (str[i] == 'z' ? 'a' : char(str[i] + 1));
                str.push_back(c);
            }
        }

        return str[k];
    }
};
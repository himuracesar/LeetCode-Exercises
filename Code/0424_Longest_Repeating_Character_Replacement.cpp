class Solution {
public:
    int characterReplacement(string s, int k) {
        if(s.length() <= k)
            return s.length();

        map<char, vector<int>> interv;
        char prev = s[0];

        int start = 0;
        for(auto i = 0; i < s.length(); i++){
            if(s[i] != prev){
                insertInterval(interv, prev, start, i-1);
                start = i;
                prev = s[i];
            }
        }

        insertInterval(interv, prev, start, s.length() - 1);

        int maxLength = 0;
        for(auto it : interv){
            vector<int> iv = it.second;
            for(auto i = 0; i < iv.size(); i += 2){
                int ak = k;
                //cout << it.first << ":: " << iv[i] << " ," << iv[i+1] << endl;
                int length = iv[i+1] - iv[i] + 1;
                for(auto j = i + 2; j < iv.size(); j += 2){
                    int space = iv[j] - iv[j-1] - 1;
                    if(space <= ak){
                        ak -= space;
                        length += space + (iv[j+1] - iv[j] + 1);
                    } else {
                        break;
                    }
                }

                length += ak;
                //maxLength = max(maxLength, length);
                maxLength = max(maxLength, min((int)s.length(), length));
            }
        }

        return maxLength;
    }

    void insertInterval(map<char, vector<int>>& interv, char key, int start, int end){
        interv[key].push_back(start);
        interv[key].push_back(end);
    }
};
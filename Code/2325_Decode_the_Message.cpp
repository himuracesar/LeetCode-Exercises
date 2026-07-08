class Solution {
public:
    string decodeMessage(string key, string message) {
        map<char, int> indices;

        int index = 0;
        for(auto i = 0; i < key.length(); i++){
            if(key[i] == ' ')
                continue;

            if(indices.find(key[i]) != indices.end())
                continue;

            indices[key[i]] = index;

            index++;
        }

        for(auto i = 0; i < message.length(); i++){
            if(message[i] == ' ')
                continue;

            message[i] = indices[message[i]] + 'a';
        }

        return message;
    }
};
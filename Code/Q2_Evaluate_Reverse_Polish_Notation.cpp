class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> ops;
        int p = 0;

        for(auto i = 0; i < tokens.size(); i++){
            if(tokens[i] == "+"){
                p--;
                ops[p-1] = ops[p-1] + ops[p];
            } else if(tokens[i] == "-"){
                p--;
                ops[p-1] = ops[p-1] - ops[p];
            } else if(tokens[i] == "*"){
                p--;
                ops[p-1] = ops[p-1] * ops[p];
            } else if(tokens[i] == "/"){
                p--;
                ops[p-1] = ops[p-1] / ops[p];
            } else {
                if(ops.size() == p)
                    ops.push_back(stoi(tokens[i]));
                else
                    ops[p] = stoi(tokens[i]);
                p++;
            }
        }

        return ops[0];
    }
};
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> stack;
        vector<int> stackCache(target.size(), 0);

        int p1 = 0;
        int p2 = 0;

        for(auto i = 1; i <= n; i++){
            stackCache[p2] = i;
            stack.push_back("Push");

            if(stackCache[p2] == target[p1]){
                p1++;
                p2++;
                if(p1 == target.size())
                    return stack;
            } else {
                stack.push_back("Pop");
            }
        }

        return stack;
    }
};
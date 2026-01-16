class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char> st;

        int points = 0;
        int a = 0;
        int b = 0;

        char firstChar = '-';
        char secondChar = '-';

        if(x >= y){
            firstChar = 'a';
            secondChar = 'b';
            a = x;
            b = y;
        } else {
            firstChar = 'b';
            secondChar = 'a';
            a = y;
            b = x;
        }

        for(auto i = 0; i < s.length(); i++){
            if(s[i] == secondChar && !st.empty() && st.top() == firstChar){
                st.pop();
                points += a;
            } else {
                st.push(s[i]);
            }
        }

        char current = '-';
        stack<char> st_aux;
        while(!st.empty()){
            if(st.top() == secondChar && !st_aux.empty() && st_aux.top() == firstChar){
                points += b;
                st_aux.pop();
            } else {
                st_aux.push(st.top());
            }

            st.pop();
        }

        return points;
    }
};
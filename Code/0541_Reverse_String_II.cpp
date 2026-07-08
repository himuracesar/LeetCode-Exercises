class Solution {
public:
    string reverseStr(string s, int k) {

        for(auto i = 0; i < s.length(); i+=2*k){
            int start = i;
            int end = min(start+k-1, (int)s.length()-1);
            
            while(start < end){
                char aux = s[start];
                s[start] = s[end];
                s[end] = aux;

                start++;
                end--;
            }
        }

        return s;
    }
};
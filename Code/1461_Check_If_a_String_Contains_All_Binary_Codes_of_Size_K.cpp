class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int counter = 0;
        int totalSubs = pow(2, k);
        int start = 0;
        int end = k-1;

        set<string> subs;
        string sb = "";
        while(s.length() - start >= k){
            sb = s.substr(start, k);

            if(subs.find(sb) == subs.end()){
                counter++;
                subs.insert(sb);
            }

            start++;
        }
        
        return (counter == totalSubs);
    }
};
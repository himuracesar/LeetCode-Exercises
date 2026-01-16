class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> numCharsInT;
        unordered_map<char, int> numCharsInSubs;

        int minLength = INT_MAX;
        int lengthSubs = t.length();

        for(auto i = 0; i < t.length(); i++)
            numCharsInT[t[i]]++;

        int index = 0;
        int leftPointer = 0;
        int start = 0;

        while(index < s.length() || lengthSubs == 0){
            //cout << "index:: " << index << endl;
            if(lengthSubs > 0){
                if(numCharsInT.find(s[index]) != numCharsInT.end()){
                    if(numCharsInT[s[index]] > numCharsInSubs[s[index]])
                        lengthSubs--; 
                    numCharsInSubs[s[index]]++;
                }
                index++;
            } else {
                //cout << "1. lengthSubs:: " << lengthSubs << " == index:: " << index << " leftPointer:: " <<  leftPointer << endl;
                if(minLength > index - leftPointer){
                    start = leftPointer;
                    minLength = index - leftPointer;
                    //subs = s.substr(leftPointer, minLength);
                }

                if(numCharsInT.find(s[leftPointer]) != numCharsInT.end()){
                    numCharsInSubs[s[leftPointer]]--;
                    //cout << s[currentCheckPoint] << " ---> " << numCharsInSubs[s[currentCheckPoint]] << " || " << numCharsInT[s[currentCheckPoint]] << endl;
                    if(numCharsInSubs[s[leftPointer]] < numCharsInT[s[leftPointer]])
                        lengthSubs++;
                }
                
                leftPointer++;
            }
        }

        minLength = (minLength == INT_MAX) ? 0 : minLength;
        
        return s.substr(start, minLength);
    }
};
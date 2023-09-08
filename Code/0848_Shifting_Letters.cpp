class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        const long MAX_LETTERS = 'z' - 'a' + 1;
        vector<long> newshifts;

        for(auto i = 0; i < shifts.size(); i++){
            newshifts.push_back(shifts[i]);
        }

        for(auto i = 0; i < newshifts.size() - 1; i++){
            int index = newshifts.size() - 2 - i;
            newshifts[index] = newshifts[index] + newshifts[index + 1];
            //cout << "index:: " << index << " " << newshifts[index] << endl;
        }
        
        for(auto i = 0; i < s.length(); i++){
            long shift = 0;
            if(newshifts[i] > MAX_LETTERS){
                shift = newshifts[i] % MAX_LETTERS;
            } else {
                shift = newshifts[i];
            }
            //cout << "__shift:: " << shift << endl;
            if(s[i] + shift > 'z'){
                shift = s[i] + shift - 'z';
                s[i] = char('a' + shift - 1);
            } else {
                //cout << "shift:: " << shift << " i:: " << i << " -- s[i]:: " << s[i] << " final:: " << (s[i] + shift) << " -- " << char(s[i] + shift) << endl;
                s[i] = char(s[i] + shift);
            }

        }
        
        return s;
    }
};
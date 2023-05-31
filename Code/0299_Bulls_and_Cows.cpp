class Solution {
public:
    string getHint(string secret, string guess) {
        map<int, int> hmsecret;
        map<int, int> hmguess;

        int bulls = 0;
        int cows = 0;

        for(auto i = 0; i < guess.length(); i++){
            if(secret.at(i) == guess.at(i))
                bulls++;
            else {
                if(hmsecret.find(guess.at(i)) != hmsecret.end() && hmsecret[guess.at(i)] > 0){
                    cows++;
                    hmsecret[guess.at(i)] = hmsecret[guess.at(i)] - 1;
                } else {
                     if(hmguess.find(guess.at(i)) != hmguess.end())
                        hmguess[guess.at(i)] = hmguess[guess.at(i)] + 1;
                    else
                        hmguess[guess.at(i)] = 1;
                }

                if(hmguess.find(secret.at(i)) != hmguess.end() && hmguess[secret.at(i)] > 0){
                    cows++;
                    hmguess[secret.at(i)] = hmguess[secret.at(i)] - 1;
                } else {
                    if(hmsecret.find(secret.at(i)) != hmsecret.end())
                        hmsecret[secret.at(i)] = hmsecret[secret.at(i)] + 1;
                    else
                        hmsecret[secret.at(i)] = 1;
                }
            }
        }

        string res = to_string(bulls) + "A" + to_string(cows) + "B";

        return res;
    }
};
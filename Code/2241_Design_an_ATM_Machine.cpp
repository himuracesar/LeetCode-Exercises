class ATM {
public:
    ATM() {
        for(auto i = 0; i < 5; i++)
            banknote.push_back(0);

        amountNotes.push_back(500);
        amountNotes.push_back(200);
        amountNotes.push_back(100);
        amountNotes.push_back(50);
        amountNotes.push_back(20);
    }
    
    void deposit(vector<int> banknotesCount) {
        for(auto i = 0; i < banknotesCount.size(); i++)
            banknote[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        vector<int> wd;
        for(auto i = 0; i < 5; i++)
            wd.push_back(0);

        for(auto i = 0; i < amountNotes.size(); i++){
            long minNumBills = amount / amountNotes[i];
            //cout << "amount:: " << amount << " n:: " << n << " banknote:: " << banknote[banknote.size() - 1 - i] << " -- " << amountNotes[i] << endl;
            int index = banknote.size() - 1 - i;

            minNumBills = min(minNumBills, banknote[index]);
            banknote[index] -= minNumBills;
            wd[index] = minNumBills;

            amount = amount - (minNumBills * amountNotes[i]);

            if(amount == 0)
                break;
        }

        vector<int> res;
        if(amount > 0){
            for(auto i = 0; i < wd.size(); i++)
                banknote[i] += wd[i];
            
            res.push_back(-1);
            return res;
        }
        else
            return wd;
    }

private:
    vector<long> banknote;
    vector<int> amountNotes;
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
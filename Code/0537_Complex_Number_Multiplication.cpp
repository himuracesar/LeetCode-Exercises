class Solution {
public:
    int strToInt(string s)
    {
        //cout << "String " << s << endl;
        bool negative = false;
        if(s.at(0) == '-')
            negative = true;
        
        int num = 0;
        for(auto i = 0; i < s.length(); i++)
        {
            int naux = s.at(i) - '0';
            if(naux >= 0 && naux <= 9)
                num = num * 10 + naux;
        }

        //cout << num << endl;
        num = (negative) ? -num : num;

        return num;
    }

    string complexNumberMultiply(string num1, string num2) {
        string n1 = "";
        string n2 = "";

        stringstream ss1(num1);
        stringstream ss2(num2);

        vector<int> vn1;
        vector<int> vn2;

        string s;
        while(getline(ss1, s, '+')){
            vn1.push_back(strToInt(s));
        }

        while(getline(ss2, s, '+')){
            vn2.push_back(strToInt(s));
        }

        int real = vn1[1] * vn2[1] * -1 + vn1[0] * vn2[0];
        int imaginary = vn1[1] * vn2[0] + vn1[0] * vn2[1];

        string res = to_string(real) + "+" + to_string(imaginary) + "i";

        return res;
    }
};
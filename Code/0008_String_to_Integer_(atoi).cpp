class Solution {
public:
    int myAtoi(string s) {
        string snum = "";
        int num = 0;
        int signCount = 0;
        int numchar = 0;
        bool isNegative = false;
        string n32 = "2147483647";

        for(auto i = 0; i < s.length(); i++)
        {
            if(s.at(i) == ' ' && numchar == 0 && signCount == 0)
                continue;

            if((s.at(i) == '-' || s.at(i) == '+') && numchar == 0)
            {
                signCount++;
                if(signCount > 1)
                    return 0;

                isNegative = s.at(i) == '-' ? true : isNegative;
            }
            else if(s.at(i) >= '0' && s.at(i) <= '9')
            {
                numchar++;
                if(s.at(i) == '0' && snum.length() == 0)
                    continue;
                snum += s.at(i);
            }
            else
                break;
        }

        bool checkMax = false;
        if(snum.length() == 0)
            return 0;
        if(snum.length() > n32.length())
            return isNegative ? -2147483648 : 2147483647;
        if(snum.length() == n32.length())
            checkMax = true;


        //cout << "num:: " << snum << endl;
        int exp = snum.length() - 1;
        for(auto i = 0; i < snum.length(); i++)
        {
            int unit = snum.at(i) - '0';
            if(checkMax)
            {
                int n32unit = n32.at(i) - '0';
                if(unit < n32unit)
                    checkMax = false;
                else if(unit > n32unit)
                    return isNegative ? -2147483648 : 2147483647;
            }

            int n = pow(10, exp) * unit;
            num += n;

            exp--;
        }

        if(isNegative)
            num = -num;

        return num;
    }
};
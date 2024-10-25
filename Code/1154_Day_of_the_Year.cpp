class Solution {
public:
    int dayOfYear(string date) {
        int daysMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        
        string syear = date.substr(0,4);
        string smonth = date.substr(5,2);
        string sday = date.substr(8,2);
        //cout << " date:: " << syear << "/" << smonth << "/" << sday << endl;

        int year = toInt(syear);
        int month = toInt(smonth);
        int day = toInt(sday);
        int numDay = 0;

        if((year % 4 == 0 && year % 100 > 0) ||
           (year % 100 == 0 && year % 400 == 0))
            daysMonths[1]++;

        for(auto i = 0; i < month; i++){
            if(i == month-1)
                numDay += day;
            else 
                numDay += daysMonths[i];
        }

        return numDay;
    }

    int toInt(string s){
        int val = 0;
        for(auto i = 0; i < s.length(); i++){
            val = val * 10 + (s[i] - '0');
        }

        return val;
    }
};
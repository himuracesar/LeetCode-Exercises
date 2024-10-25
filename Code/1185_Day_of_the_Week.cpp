class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string days[] = {"Thursday","Friday","Saturday","Sunday","Monday","Tuesday","Wednesday"};

        int daysPerMonth[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

        int totalDays = (year - 1971) * 365;
        for(auto i = 1972; i < year; i += 4)
            totalDays++; 

        if( (year % 4 == 0 && year % 100 > 0) || (year % 100 == 0 && year % 400 == 0) )
            if(month > 2)
                totalDays++;
            
        for(auto i = 1; i < month; i++)
            totalDays += daysPerMonth[i];

        totalDays += day;
        
        return days[(totalDays % 7)];
    }
};
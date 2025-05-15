class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        string cat1 = "";
        string cat2 = "";

        long vol = (long)length * (long)width * (long)height;
        if(length >= 10000 || width >= 10000 || height >= 10000)
            cat1 = "Bulky";
        else if(vol >= 1000000000)
            cat1 = "Bulky";
        
        if (mass >= 100)
            cat2 = "Heavy";
        
        if(cat1 == "Bulky" && cat2 == "Heavy")
            return "Both";
        if(cat1 == "" && cat2 == "")
            return "Neither";
        if(cat1 == "Bulky" && cat2 == "")
            return "Bulky";
        if(cat1 == "" && cat2 == "Heavy")
            return "Heavy";

        return "";
    }
};
class Solution {
public:
    int countVowelStrings(int n) {
        return 
            count(n-1, 'a') + 
            count(n-1, 'e') + 
            count(n-1, 'i') + 
            count(n-1, 'o') + 
            count(n-1, 'u');
    }

    int count(int n, char lc){
        if(n == 0)
            return 1;

        int a = (lc <= 'a') ? count(n-1, 'a') : 0;
        int e = (lc <= 'e') ? count(n-1, 'e') : 0;
        int i = (lc <= 'i') ? count(n-1, 'i') : 0;
        int o = (lc <= 'o') ? count(n-1, 'o') : 0;
        int u = (lc <= 'u') ? count(n-1, 'u') : 0;

        return a + e + i + o + u;
    }
};
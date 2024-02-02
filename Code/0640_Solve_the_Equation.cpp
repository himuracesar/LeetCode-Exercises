class Solution {
public:
    string solveEquation(string equation) {
        vector<int> eq;
        for(auto i = 0; i < 4; i++)
            eq.push_back(0);

        bool equal = false;
        bool sign = true;
        bool expl = false;
        int coef = 0;
        for(auto i = 0; i < equation.length(); i++){
            if(equation[i] == '+'){
                pushCoeficient(coef, sign, equal, eq);
                coef = 0;
                sign = true;
                expl = false;
            } else if(equation[i] == '-'){
                pushCoeficient(coef, sign, equal, eq);
                coef = 0;
                sign = false;
                expl = false;
            } else if(equation[i] == '='){
                pushCoeficient(coef, sign, equal, eq);
                coef = 0;
                equal = true;
                sign = true;
                expl = false;
            } else if(equation[i] == 'x'){
                coef = (coef == 0 && !expl) ? 1 : coef;
                if(!equal){
                    if(!sign)
                        eq[0] -= coef;
                    else
                        eq[0] += coef;
                } else {
                    if(!sign)
                        eq[2] -= coef;
                    else
                        eq[2] += coef;
                }
                coef = 0;
                expl = false;
            } else {
                coef = coef * 10 + equation[i] - '0';
                expl = true;
            }
        }

        pushCoeficient(coef, sign, equal, eq);

        /*for(auto i = 0; i < 4; i++)
            cout << eq[i] << " | " << endl;*/

        int x = eq[0] - eq[2];
        int c = eq[3] - eq[1];
        if(x == 0 && c == 0)
            return "Infinite solutions";
        else if(x == 0 && c != 0)
            return "No solution";
        
        int ans = c / x;

        return "x=" + to_string(ans);   
    }

    void pushCoeficient(int coef, bool sign, bool equal, vector<int>& eq){
        if(!equal){
            if(!sign)
                eq[1] -= coef;
            else
                eq[1] += coef;
        } else {
            if(!sign)
                eq[3] -= coef;
            else
                eq[3] += coef;
        }
    }
};
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> pars;
        pars.resize(n);
        pars[0].push_back("()");

        map<string, string> mpars;

        for(auto i = 2; i <= n; i++)
        {
            int start = 0;
            int end = i - 2;
            while(start <= end)
            {
                for(auto j = 0; j < pars[start].size(); j++)
                {
                    for(auto k = 0; k < pars[end].size(); k++)
                    {
                        if(mpars.find(pars[start][j] + pars[end][k]) == mpars.end())
                        {
                            mpars[pars[start][j] + pars[end][k]] = pars[start][j] + pars[end][k];
                            pars[i - 1].push_back(pars[start][j] + pars[end][k]);
                        }

                        if(mpars.find(pars[end][k] + pars[start][j]) == mpars.end())
                        {
                            mpars[pars[end][k] + pars[start][j]] = pars[end][k] + pars[start][j];
                            pars[i - 1].push_back(pars[end][k] + pars[start][j]);
                        }

                        if(start == 0)
                        {
                            if(mpars.find("(" + pars[end][k] + ")") == mpars.end())
                            {
                                mpars["(" + pars[end][k] + ")"] = "(" + pars[end][k] + ")";
                                pars[i - 1].push_back("(" + pars[end][k] + ")");
                            }
                        }
                    }
                }

                start++;
                end--;
            }
        }

        return pars[n - 1];
    }
};
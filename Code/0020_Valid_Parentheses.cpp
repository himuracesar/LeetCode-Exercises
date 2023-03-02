class Solution {
public:
    bool isValid(string s) {
        stack<char> parentheses;
        
        if(s.length() < 2)
            return false;
        
        for(auto i = 0; i < s.length(); i++)
        {
            switch(s.at(i))
            {
                case '(' :
                case '[' :
                case '{' :
                    parentheses.push(s.at(i));
                    break;
                    
                case ')':
                    if(!parentheses.empty() && parentheses.top() == '(')
                        parentheses.pop();
                    else
                        return false;
                    break;
                case ']':
                    if(!parentheses.empty() && parentheses.top() == '[')
                        parentheses.pop();
                    else
                        return false;
                    break;
                case '}':
                    if(!parentheses.empty() && parentheses.top() == '{')
                        parentheses.pop();
                    else
                        return false;
                    break;
            }
        }
        
        if(parentheses.empty())
            return true;
        else
            return false;
    }
};
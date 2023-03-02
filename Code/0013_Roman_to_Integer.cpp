class Solution {
public:
    int romanToInt(string s) {
        stack<int> nums;
        
        string c;
        
        while(s.length() > 0)
        {
            c = s.substr(0,1);
            s = s.substr(1, s.length());
            
            switch(*c.c_str())
            {
                case 'I':
                    nums.push(1);
                    break;
                    
                case 'V':
                    if(!nums.empty() && nums.top() == 1)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(5);
                    break;
                
                case 'X':
                    if(!nums.empty() && nums.top() == 1)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(10);
                    break;
                    
                case 'L':
                    if(!nums.empty() && nums.top() == 10)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(50);
                    break;
                    
                case 'C':
                    if(!nums.empty() && nums.top() == 10)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(100);
                    break;
                
                case 'D':
                    if(!nums.empty() && nums.top() == 100)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(500);
                    break;
                    
                case 'M':
                    if(!nums.empty() && nums.top() == 100)
                    {
                        int n = nums.top();
                        nums.pop();
                        nums.push( -n );
                    }
                    
                    nums.push(1000);
                    break;
            }
        }
        
        int sum = 0;
        while(!nums.empty())
        {
            sum += nums.top();
            nums.pop();
        }
        
        return sum;
    }
};
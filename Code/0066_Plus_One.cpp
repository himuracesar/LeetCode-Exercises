class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int ac = 1;
        int index = digits.size() - 1;
        
        stack<int> st;
        
        while(index >= 0)
        {
            int sum = digits[index] + ac;
            ac = (ac > 0) ? ac - 1 : ac;
            index--;

            if(sum >= 10)
            {
                sum -= 10;
                ac++;
            }

            st.push(sum);
        }
        
        if(ac > 0)
            st.push(ac);
        
        vector<int> v;
        while(!st.empty())
        {
            v.push_back(st.top());
            st.pop();
        }
        
        return v;
    }
};
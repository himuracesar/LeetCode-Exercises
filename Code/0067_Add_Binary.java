class Solution {
    public String addBinary(String a, String b) {
        int i = a.length() - 1;
        int j = b.length() - 1;
        int ac = 0;
        int sum = 0;
        int ca = 0;
        int cb = 0;
        
        Stack<String> stack = new Stack<String>();
        
        while(i >= 0 || j >= 0)
        {
            if(i >= 0)
            {
                ca = a.charAt(i) - "0".charAt(0);
                i--;
            }
            else
                ca = 0;
            
            if(j >= 0)
            {
                cb = b.charAt(j) - "0".charAt(0);
                j--;
            }
            else
                cb = 0;
            
            //System.out.println("ca:: " + ca + " cb:: " + cb + " ac:: " + ac);
            sum = ca + cb + ac;
            ac = 0;
            
            if(sum >= 2)
            {
                sum -= 2;
                ac = 1;
            }
            
            stack.push(Integer.toString(sum));
            
            sum = 0;
        }
        
        if(ac == 1)
            stack.push(Integer.toString(ac));
        
        String ans = "";
        while(!stack.empty())
        {
            ans += stack.peek();
            stack.pop();
        }
        
        return ans;
    }
}
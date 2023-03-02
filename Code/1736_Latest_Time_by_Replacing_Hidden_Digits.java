class Solution {
    public String maximumTime(String time) {
        String lastHour = "";
        
        String h1 = time.substring(0,1);
        String h2 = time.substring(1,2);
        String m1 = time.substring(3,4);
        String m2 = time.substring(4,5);
        
        
        if(h1.equals("?"))
        {
            if(!h2.equals("?") && Integer.parseInt(h2) > 3)
                h1 = "1";
            else if(h2.equals("?") || Integer.parseInt(h2) <= 3)
               h1 = "2";
        }
       
        if(h2.equals("?"))
        {
            if(h1.equals("1") || h1.equals("0"))
                h2 = "9";
            else if(h1.equals("2"))
                h2 = "3";
        }
        
        m1 = (m1.equals("?")) ? "5" : m1;
        m2 = (m2.equals("?")) ? "9" : m2;
        
        return h1 + h2 + ":" + m1 + m2;
    }
}
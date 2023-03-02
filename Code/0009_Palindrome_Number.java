class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
            return false;
        else if(x < 10)
            return true;
        else{
            String s = Integer.toString(x);
            
            int start = 0;
            int end = s.length() - 1;
            
            while(start <= end){
                if(s.charAt(start) == s.charAt(end)){
                    start++;
                    end--;
                }
                else
                    return false;
            }
            
            return true;
        }
    }
}
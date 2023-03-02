class Solution {
    public int lengthOfLastWord(String s) {
        int max = 0;
        
        String str[] = s.split(" ");
        
        /*for(int i = 0; i < str.length; i++)
        {
            max = str[i].length();
        }
        
        return max;*/
        
        return str[str.length - 1].length();
    }
}
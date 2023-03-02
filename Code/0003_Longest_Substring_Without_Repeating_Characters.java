class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> hm = new HashMap<Character, Integer>();
        int length = 0;
        int maxLength = 0;
        int lastIndex = -1;
        
        for(int i = 0; i < s.length(); i++)
        {
            if(hm.get(s.charAt(i)) == null)
            {
                hm.put(s.charAt(i), i);
                length++;
                //System.out.println("length:: " + length);
            }
            else if(hm.get(s.charAt(i)) >= lastIndex)
            {
                maxLength = Math.max(maxLength, length);
                length = i - hm.get(s.charAt(i));
                //System.out.println("-- length:: " + length);
                lastIndex = hm.get(s.charAt(i));
                hm.put(s.charAt(i), i);
                //System.out.println("-- lastIndex:: " + lastIndex);
            }
            else
            {
                length++;
                hm.put(s.charAt(i), i);
                //System.out.println("++ length:: " + length);
            }
        }

        maxLength = Math.max(maxLength, length);

        return maxLength;
    }
}
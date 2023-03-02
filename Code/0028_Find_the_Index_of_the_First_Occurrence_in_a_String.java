class Solution {
    public int strStr(String haystack, String needle) {
        int length = haystack.length() - needle.length() + 1;
        for(int i = 0; i < length; i++)
        {
            if(haystack.charAt(i) == needle.charAt(0))
            {
                String haystackss = haystack.substring(i, i + needle.length());
                //System.out.println("ss:: " + haystackss);
                boolean found = true;
                for(int j = 0; j < needle.length(); j++)
                {
                    if(haystackss.charAt(j) != needle.charAt(j))
                    {
                        found = false;
                        break;
                    }
                }
                if(found)
                    return i;
            }
        }

        return -1;
    }
}
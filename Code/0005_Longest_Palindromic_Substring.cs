public class Solution {
    public string LongestPalindrome(string s) {
        int n = s.Length;

        for(int i = 0; i < n; i++)
        {
            int start = 0;
            int length = n - i;
            while(start + length <= n)
            {
                //Console.WriteLine("start:: " + start + " End:: " + end);
                string ss = s.Substring(start, length);
                //Console.WriteLine(ss);
                if(IsPalindrome(ss))
                    return ss;

                start++;
                //end++;
            }
        }

        return s[0].ToString();
    }

    bool IsPalindrome(string s)
    {
        int p1 = 0;
        int p2 = 0;

        if(s.Length % 2 == 0)
        {
            p2 = s.Length / 2;
            p1 = p2 - 1;
        }
        else
        {
            p1 = s.Length / 2 - 1;
            p2 = s.Length / 2 + 1 ;
        }

        while(p1 < -1 || p2 < s.Length)
        {
            if(s[p1] == s[p2])
            {
                p1--;
                p2++;
            }
            else
                return false;
        }

        return true;
    }
}
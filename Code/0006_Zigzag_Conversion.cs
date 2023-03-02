public class Solution {
    public string Convert(string s, int numRows) {
        string res = "";

        int sizeStep = 1;
        if(numRows > 1)
            sizeStep = numRows * 2 - 2;

        int step1 = sizeStep;
        int step2 = 0;
        int finalStep = 0;

        for(int i = 0; i < numRows; i++)
        {
            int index = i;
            while(index < s.Length)
            {
                res += s[index];

                if(step1 == 0 || step2 == 0)
                    finalStep = sizeStep;
                else if(finalStep == step1)
                    finalStep = step2;
                else
                    finalStep = step1;

                index += finalStep;
            }

            step1 -= 2;
            step2 += 2;
            finalStep = 0;
        }

        return res;
    }
}
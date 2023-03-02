class Solution {
    public int reverse(int x) {
        int nreverse = 0;
        Queue<Integer> q = new LinkedList<Integer>();
        boolean isNegative = false;

        if(x < 0)
        {
            isNegative = true;
            x *= -1;
        }

        while(x > 0)
        {
            q.add(x % 10);
            x = x / 10;
        }

        String num32 = "2147483647";
        boolean checker = false;
        if(q.size() == num32.length())
            checker = true;

        int i = 0;
        while(!q.isEmpty())
        {
            if(checker)
            {
                int n32 = num32.charAt(i++) - '0';
                if(q.peek() > n32)
                    return 0;
                else if(q.peek() < n32)
                    checker = false;
            }

            nreverse = nreverse * 10 + q.peek();
            q.remove();
        }

        if(isNegative)
            nreverse = -nreverse;

        return nreverse;
    }
}
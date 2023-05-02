class Solution {
    public int countPrimes(int n) {
        List<Integer> primes = new ArrayList<Integer>();
        for(int i = 0; i < n; i++)
        {
            if(i > 1)
                primes.add(1);
            else
                primes.add(0);
        }


        int sqrt_n = (int)Math.sqrt(n);
        for(int i = 2;  i <= sqrt_n; i++)
        {
            if(primes.get(i) == 1)
                for(int j = 2; i * j < n; j++)
                    primes.set(i * j, 0);
        }

        int counter = 0;
        for(int i = 2; i < primes.size(); i++)
            if(primes.get(i) == 1)
                counter++;

        return counter;
    }
}
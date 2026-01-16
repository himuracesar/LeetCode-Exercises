class Solution {
public:
    int climbStairs(int n) {
        vector<int> memo = vector<int>(n + 1, -1);

        memo[0] = 1;
        memo[1] = 1;

        return fibonacci(n, memo);
    }

    int fibonacci(int n, vector<int>& memo){
        if(memo[n] == -1)
            memo[n] = fibonacci(n-2, memo) + fibonacci(n-1, memo);

        return memo[n];
    }

};
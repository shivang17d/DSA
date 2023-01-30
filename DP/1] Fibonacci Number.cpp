// https://leetcode.com/problems/fibonacci-number/


// Recursion  TC = O(2^N)  SC = O(N)

class Solution {
public:
    int fib(int n) {
        if(n <= 1) return n;
        return fib(n-1) + fib(n-2);
    }
};

// Memoization (Top-Down Approach) TC --> O(n)       SC --> O(n) + O(n)  ---> (Recursion Stack Space and Array)

class Solution {
public:
    int help(int n , vector<int>&dp) {
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] = help(n-1,dp) + help(n-2,dp);
    }
    int fib(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};

// Tabulation (Bottom-Up Approach)   TC --> O(n)       SC --> O(1)

class Solution {
public:
    int fib(int n) {
        if(n<=1)
        {
            return n;
        }
        int prev1 = 1;
        int prev2 = 0;
        for(int i = 2 ; i <= n ; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
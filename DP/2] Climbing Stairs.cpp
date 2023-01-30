// https://leetcode.com/problems/climbing-stairs/


// Recursion   TC = O(2^N)  SC = O(N) (for a recursive series)

class Solution {
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};


// Memoization  TC --> O(n)       SC --> O(n) + O(n)  ---> (Recursion Stack Space and Array)

class Solution {
public:
    int help(int n , vector<int> &dp) {
        if(n<=1) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n] = help(n-1,dp) + help(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return help(n,dp);
    }
};


// Tabulation   TC --> O(n)       SC --> O(1)

class Solution {
public:
    int climbStairs(int n) {
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2 ; i <= n ; i++)
        {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};
// https://www.codingninjas.com/codestudio/problems/frog-jump_3621012

// Recursive   TC --> O(2^N)  SC --> O(N) + O(N) ≈ O(N)  (recursion stack space(O(N)) and an array (again O(N)))
#include <bits/stdc++.h> 
using namespace std;
int help(int idx,vector<int> &heights)
{
    if(idx == 0) return 0;

    int left = help(idx-1,heights) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;  // Right Recurrence will not always exist
    if(idx > 1) right = help(idx-2,heights) + abs(heights[idx] - heights[idx-2]);
    return min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    return help(n-1,heights);
}


//Memoization    TC --> O(N)       SC --> O(N) + O(N) ≈ O(N)  
#include <bits/stdc++.h> 
using namespace std;
int help(int idx,vector<int> &heights, vector<int> &dp)
{
    if(idx == 0) return 0;
    if(dp[idx] != -1) return dp[idx];

    int left = help(idx-1,heights,dp) + abs(heights[idx] - heights[idx-1]);
    int right = INT_MAX;  // Right Recurrence will not always exist
    if(idx > 1) right = help(idx-2,heights,dp) + abs(heights[idx] - heights[idx-2]);
    return dp[idx] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,-1);
    return help(n-1,heights,dp);
}


//Tabulation        TC --> O(N)       SC --> O(N)
#include <bits/stdc++.h> 
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n,0);
    dp[0] = 0;
    for(int i = 1; i <n ; i++)
    {
        int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if(i > 1) ss = dp[i-2] + abs(heights[i] - heights[i-2]);
        dp[i] = min(fs,ss);
    }
    return dp[n-1];
}


//Tabulation with Space Optimization  TC --> O(N)       SC --> O(1)
#include <bits/stdc++.h> 
using namespace std;
int frogJump(int n, vector<int> &heights)
{
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 1 ; i < n ; i++) {
        int fs = prev1 + abs(heights[i] - heights[i-1]);
        int ss =  INT_MAX;
        if(i>1) ss = prev2 + abs(heights[i] - heights[i-2]);
        int curr = min(fs,ss);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

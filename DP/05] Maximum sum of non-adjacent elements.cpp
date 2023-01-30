//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261

//Memoization   Time Complexity: O(N)   Space Complexity: O(N) + O(N) ≈ O(N)
#include <bits/stdc++.h> 
using namespace std;
int solveUtil(int ind, vector<int>& arr, vector<int>& dp){
    
    if(dp[ind]!=-1) return dp[ind];
    
    if(ind==0) return arr[ind];
    if(ind<0)  return 0;
    
    int pick= arr[ind]+ solveUtil(ind-2, arr,dp);
    int nonPick = 0 + solveUtil(ind-1, arr, dp);
    
    return dp[ind]=max(pick, nonPick);
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n-1, arr, dp);
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    return solve(nums.size(),nums);
}



//Tabulation  Time Complexity: O(N)  Space Complexity: O(N)
#include <bits/stdc++.h> 
using namespace std;
int solveUtil(int n, vector<int>& arr, vector<int>& dp){
    
    dp[0]= arr[0];
    
    for(int i=1 ;i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    return dp[n-1];
}

int solve(int n, vector<int>& arr){
    vector<int> dp(n,-1);
    return solveUtil(n, arr, dp);
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    return solve(nums.size(),nums);
}



// Space Optimization: Time Complexity: O(N)  Space Complexity: O(1)
#include <bits/stdc++.h> 
using namespace std;
int solve(int n, vector<int>& arr){
    int prev1 = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev1;
        
        int curr = max(pick, nonPick);
        prev2 = prev1;
        prev1= curr;
        
    }
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    
    return solve(nums.size(),nums);
}

// https://www.codingninjas.com/codestudio/problems/house-robber_839733
#include <bits/stdc++.h> 
using namespace std;
long long int solve(vector<long long int> &nums)
{
    long long int n = nums.size();
    vector<int>dp(n,-1);
    long long int prev1 = nums[0];
    long long int prev2;
    for(long long int i = 1 ; i < n ; i++)
    {
        long long int pick = nums[i];
        if(i > 1) pick += prev2;
        long long int nonpick = 0 + prev1;
        long long int curr = max(pick,nonpick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    long long int n = valueInHouse.size();
    vector<long long int> temp1, temp2;
    if(n==1) return valueInHouse[0];
    for(long long int i = 0 ; i < n ; i++) {
        if(i != 0) temp1.push_back(valueInHouse[i]);
        if(i != n-1) temp2.push_back(valueInHouse[i]);
    }
    return max(solve(temp1),solve(temp2));
}
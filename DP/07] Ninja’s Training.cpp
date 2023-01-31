// https://www.codingninjas.com/codestudio/problems/ninja-s-training_3621003

// Recursion
#include<bits/stdc++.h>
using namespace std;
int solve(int day,int last, vector<vector<int>> &points)
{
    if(day == 0) 
    {
        int maxi = 0;
        for(int task = 0 ; task < 3 ;task++) 
        {
            if(task != last) 
            {
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    for(int task = 0 ; task < 3 ; task++) 
    {
        if(task != last) 
        {
            maxi = max(maxi,points[day][task] + solve(day-1,task,points));
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{ 
    return solve(n-1,3,points);
}

//Memoization
#include<bits/stdc++.h>
using namespace std;
int solve(int day,int last, vector<vector<int>> &points,vector<vector<int>> &dp)
{
    if(dp[day][last] != -1) return dp[day][last];
    if(day == 0) 
    {
        int maxi = 0;
        for(int task = 0 ; task < 3 ;task++) 
        {
            if(task != last) 
            {
                maxi = max(maxi,points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    for(int task = 0 ; task < 3 ; task++) 
    {
        if(task != last) 
        {
            maxi = max(maxi,points[day][task] + solve(day-1,task,points,dp));
        }
    }
    return dp[day][last] =maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{ 
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return solve(n-1,3,points,dp);
}


//Tabulation
#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1 ; day < n ; day++) 
    {
        for(int last = 0 ; last < 4 ; last++)
        {
            dp[day][last] = 0;
            for(int task = 0 ; task <3; task++) 
            {
                if(task != last) 
                {
                    int point = points[day][task] + dp[day-1][task];
                    dp[day][last] = max(dp[day][last],point);
                }
                
            }
        }
    }
    return dp[n-1][3];
}


//Tabulation with Space Optimization
#include<bits/stdc++.h>
using namespace std;
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<int>prev(4,0);
    prev[0] = max(points[0][1],points[0][2]);
    prev[1] = max(points[0][0],points[0][2]);
    prev[2] = max(points[0][0],points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});

    for(int day = 1 ; day < n ; day++) 
    {
        vector<int> temp(4,0);
        for(int last = 0 ; last < 4 ; last++)
        {
            temp[last] = 0;
            for(int task = 0 ; task <3; task++) 
            {
            
                if(task != last) 
                {
                    temp[last] = max(temp[last],points[day][task] + prev[task]);
                }
                
            }
        }
        prev = temp;
    }

    return prev[3];
}
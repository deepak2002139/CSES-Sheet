
//                                                       A Template by Deepak Kumar 


#include <bits/stdc++.h>
using namespace std;
// int solve(int i,vl & price,vl & pages,int x)
// {
//     int n=pages.size();
//     if(i>=n)
//     return 0;
//     if(dp[i][x]!=-1)
//     return dp[i][x];
//     int take=0;
//     if(x-price[i]>=0)
//     take=pages[i]+solve(i+1,price,pages,x-price[i]);
//     int nottake=solve(i+1,price,pages,x);
//     return dp[i][x]=max(take,nottake);
// }

int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> price(n),pages(n);
    for(int i=0;i<n;i++)
    {
        cin>>price[i];
    }  
    for(int i=0;i<=n;i++)
    {
        cin>>pages[i];
    }  
    vector<vector<int>> dp(n+1,vector<int >(x+1,0));
    // cout<<solve(0,price,pages,x);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=price[i-1])
            dp[i][j]=max(dp[i][j],dp[i-1][j-price[i-1]]+pages[i-1]);
        }
    }
    cout<<dp[n][x];
    return 0;
}

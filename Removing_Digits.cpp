#define ll long long
#include <bits/stdc++.h>
using namespace std;
ll dp[1000001];
ll solve(ll n)
{
    if((dp[n]!=-1))
    return dp[n];
    if(n<10)
    return dp[n]=1;
    ll ans=INT_MAX;
    ll p=n;
    while(p)
    {
        ll res=p%10;
        if(res!=0)
        ans=min(ans,1+solve(n-p%10));
        p/=10;
    }
    return dp[n]=ans;
}
int main()
{
    ll n;
    cin>>n;
    ll count=0; 
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    solve(n);
    cout<<dp[n]<<endl;
    return 0;
}
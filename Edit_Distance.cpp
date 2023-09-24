
//                                                       A Template by Deepak Kumar

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef map<ll, ll> mll;
typedef map<string, ll> msl;
typedef map<char, ll> mcl;
typedef map<string, string> mss;
#define BOLT                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define pf push_front
#define pob pop_back
#define fi first
#define se second
#define in insert
#define mp make_pair
#define rep(i, a, n) for (ll i = a; i < n; i++)
#define repr(i, n, b) for (ll i = n; i > b; i--)
#define repv(v) for (auto x : v)
#define all(v) v.begin(), v.end()
#define mem(a, b) memset(a, b, sizeof a)
#define w(t)  \
    ll t;     \
    cin >> t; \
    while (t--)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define ins   \
    string s; \
    cin >> s;
#define mod 1000000007

int main()
{
    BOLT;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    ll n = s1.size();
    ll m = s2.size();
    vvl dp(n + 1, vl(m + 1, 0));
    for(ll i=1;i<=n;i++)
    {
        dp[i][0]=i;
    }
    for(ll j=1;j<=m;j++)
    {
        dp[0][j]=j;
    }
    for (ll i = 1; i <= n; i++)
    {
        for (ll j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                ll mini = min(dp[i - 1][j], dp[i][j - 1]);
                dp[i][j] = 1 + min(dp[i - 1][j-1],mini);
            }
        }
    }
    // for(auto it:dp)
    // {
    //     for(auto it1:it)
    //     {
    //         cout<<it1<<" ";
    //     }
    //     cout<<endl;
    // }
    cout << dp[n][m];
    return 0;
}

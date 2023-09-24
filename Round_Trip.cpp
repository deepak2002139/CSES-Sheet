
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
#define print(vec)                       \
    for (int k = 0; k < vec.size(); k++) \
    cout << vec[k] <<
;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll lcm(ll a, ll b)
{
    return (a / gcd(a, b)) * b;
}
int fact[1000001];
void factorial()
{
    fact[0] = fact[1] = 1;
    for (int i = 2; i < 1000001; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}
// bool dfs(ll i,map<ll,vl>&mp,ll j,vl res,ll count,vl &vis)
// {
//     if(i==j && res.size()>1)
//     return true;
//     if(vis[i]==1)
//     return false;
//     vis[i]=1;
//     res.push_back(i);
//     for(auto it:mp[i])
//     {
//         dfs(it,mp,j,res,count+1,vis);
//     }
//     vis[i]=0;
//     res.pop_back();
//     return false;
// }
ll result;
bool dfs(ll i, map<ll, vl> &mp, ll j, vl &res, ll count, vl &vis)
{
    if (i==j)
    {
        res.push_back(i);
        result=count+1;
        return true;
    }
    if (vis[i]==1)
    return false;
    vis[i] = 1;
    res.push_back(i);
    for (auto it : mp[i])
    {
        if (dfs(it, mp, j, res, count+1, vis))
        {
            return true;
        }
    }
    return false;
}

int main()
{
    BOLT;
    ll n, m;
    cin >> n >> m;
    map<ll, vl> mp;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    vl arr;
    for (int i = 1; i <= n; i++)
    {
        vl vis(n+1,0);
        vl res;
        ll count = 1;
        if(vis[i]==0)
        for (auto it : mp[i])
        {
            res.push_back(i);
            if (dfs(it, mp, i, res,count,vis))
            {
                arr = res;
                break;
            }
            res.pop_back();
        }
    }
    cout << result << endl;
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}

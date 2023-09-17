
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
#define BOLT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
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
#define w(t) ll t;cin >> t;while (t--)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
#define ins string s;cin>>s;
#define mod 1000000007
#define print(vec) for(int k=0;k<vec.size();k++)cout<<vec[k]<<
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
  fact[0]=fact[1]=1;
 for(int i=2;i<1000001;i++)
  {
      fact[i]=(fact[i-1]*i)%mod; 
  }
}

//*************DSU******************
ll parent[200001];
ll sz[200001];
void make(ll v)
{
    parent[v] = v;
    sz[v] = 1;
}
ll find(ll v)
{
    if (parent[v] == v)
        return v;
    else // path compresssion
        return parent[v] = find(parent[v]);
}
void Union(ll a, ll b)
{
    a =find(a);
    b =find(b);
    if (a != b)
    { // union by size
        if (sz[a]<sz[b])
            swap(a,b);
        parent[b] = a;
        // b ka  tree ko a ka nicha joda hai
        sz[a]+=sz[b];
    }
}

int main()
{
    BOLT;
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=0;i<n;i++)
    {
        make(i+1);
    }
    vvl res;
    for(int i=0;i<m;i++)
    {
        ll a,b;
        cin>>a>>b;
        Union(a,b);
    }

    for(int i=2;i<=n;i++)
    {
        if(find(i-1)==find(i))
        continue;
        else
        {
            Union(i-1,i);
            ans++;
            res.push_back({i-1,i});
        }
    }
    cout<<ans<<endl;
    for(auto it:res)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }
    return 0;
}

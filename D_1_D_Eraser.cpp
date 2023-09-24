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
int main()
{
    BOLT;
    w(t)
    {
        ll n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>res;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='B')
            res.push_back(i);
        }
        ll ans=0;
        vector<bool>vis(n,false);
        for(int i=0;i<res.size();i++)
        {
            if(vis[res[i]]==false)
            {
                ans++;
                for(int j=res[i];j<res[i]+k && j<n;j++)
                {
                    vis[j]=true;
                }
            }
        }
        cout<<ans<<endl;
    }          
    return 0;
}
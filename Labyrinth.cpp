
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
class TrieNode
{
public:
   TrieNode *child[26];
    bool flag;
    TrieNode()
    {
        flag = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
    bool check(char c)
    {
        return (child[c - 'a'] != NULL);
    }
    void put(char c, TrieNode *node)
    {
        child[c - 'a'] = node;
    }
    TrieNode *get(char c)
    {
        return child[c - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    bool isLast()
   {
        return flag;
   }
};
class Trie
{
public:
    TrieNode *root;
 
   Trie()
    {
        root = new TrieNode();
    }
    void insert(string word)
    {
        TrieNode *node = root;
        for (auto &i : word)
        {
            if (!(node->check(i)))
            {
                node->put(i, new TrieNode());
            }
            node = node->get(i);
        }
        node->setEnd();
    }
    bool search(string word)
    {
        TrieNode *node = root;
        for (auto &i : word)
        {
            if (!(node->check(i)))
            {
                return false;
            }
            node = node->get(i);
        }
        return node->isLast();
    }
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (auto &i : prefix)
        {
            if (!(node->check(i)))
                return false;
            node = node->get(i);
        }
        return true;
    }
};
//  End of Trie Template----
//************PRIME CHECK************* 
bool checkp(int n)
{
  if(n == 1)
return false;
 for (int i = 2; i * i <= n; i++)
{
if(n % i == 0)
return false;
}
return true;
}
//**************SIEVE****************
// BOOL HAS LESS TIME COMPLEXITY THAN INT
vector<bool>vis(9000001,1);
void sieve()
{
   for (int i=2;i*i<= 9000001; i++)
   {
    if (vis[i] == true)
    {
       for(int j = i * i; j <= 9000001; j += i)
          vis[j]=false;
    }
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
//***********prime factorization*****
vector<pair<ll, ll>> pf(ll n)
{
    vector<pair<ll, ll>> ans;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n%i==0)
        {
            ll cnt=0;
            while (n % i == 0)
            {
                cnt++;
                 n/=i;
            }
            pair<ll, ll> p;
            p.first = i;
            p.second = cnt;
           ans.push_back(p);
        }
    }
    if(n > 1)
   {
        pair<ll, ll> p;
        p.first = n;
        p.second = 1;
        ans.push_back(p);
    }
return ans;
}
//**************bin exp************
ll binex(ll base,ll exp, ll M)
{
    if (exp== 0)
        return 1;
    ll res=binex(base, exp / 2, M);
    if (exp % 2 == 1)
        return (((res * res) % M) * base) % M;
    else
        return (res * res) % M;
}
 
ll pwr(ll a, ll n)
{
    ll res = 1;
    while (n)

    {
        if (n % 2)
        {
            res *= a;
            n--;
       }
       else
       {
            a *= a;
            n /= 2;
        }
    }
    return res;
}

//***********pop_count*******
ll ppc(ll n)
{
   ll c=0;
   for(c;c<n;++c)
    n&=n-1;
   return c;
}
//***********CEIL************
ll ceill(ll up, ll down)
{
    ll res=up/down;
    if(up%down!=0)
    res++;
    return res;
}
ll ncr(int n,int r)
{
    return fact[n]/(fact[r]*fact[n-r]);
}
ll npr(int n, int r)
{
    return fact[n]/(fact[n-r]);
}

int main()
{
    BOLT;
    ll n,m;      
    return 0;
}

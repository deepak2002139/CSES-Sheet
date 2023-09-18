
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
        flag=false;
        for(int i=0;i<26;i++)
        child[i]=NULL;
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
ll dp[5001];
int main()
{
    BOLT;
    string s;
    cin>>s;
    ll n=s.size();
    Trie *t=new Trie();
    ll k;
    cin>>k;
    while(k--)
    {
        string x;
        cin>>x;
        t->insert(x);
    }
    memset(dp,0,sizeof(dp));
    dp[n]=1;
    for(ll i=n-1;i>=0;i--)
    {
        string res=s.substr(i);
        if(t->search(res))
        {
            dp[i]=1+dp[i+1];
        }
        else
        dp[i]=dp[i+1];
    }
    cout<<dp[0]<<endl;
    return 0;
}

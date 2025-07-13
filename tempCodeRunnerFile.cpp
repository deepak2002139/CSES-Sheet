#define ll long long
#include <bits/stdc++.h>
using namespace std;
long long solve(int N,int K,string S) {
    string s=S;
    int n=N;
    unordered_map<char,int>mpp;
    for(int i=0;i<n;i++) mpp[s[i]]++;
    vector<pair<int,char>>v;
    for(auto x:mpp) {
        v.push_back({x.second,x.first});
    }
    sort(v.rbegin(),v.rend());
    if(v.size()<K) return 0;
    long long ans=1,mod=1000000007;
    for(int i=0;i<K;i++) {
        ans*=v[i].first; ans%=mod;
    }
    return ans;
}1
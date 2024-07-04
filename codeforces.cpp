#include <bits/stdc++.h>
#define ll long long
#define int long long
#define loop(i,a,b) std::(int i=a;i<b;i++)
#define rloop(i,a,b) std::for(int i=a;i>=b;i--)
#define rep(i,n) rep(i,0,n)
#define el cout<<endl;
#define cin(a) int a;cin>>a;
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define input(a,n) for(int j=0;j<n;j++) cin>>a[j];
#define debug(a) for(int j=0;j<a.size();j++) cout<<a[j]<<' ';cout<<endl;
#define dbg(x) cout << #x << " = " << x << endl;
#define vpii vector<pair<int,int>>
#define sis string s;
#define sin string s;cin>>s;
#define db double
#define sz(x) static_cast<int>((x).size())
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define push push_back
#define pop pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bpc(x) __builtin_popcountll(x);
#define ctz(x) __builtin_ctz(x);//counts tailing zeros
// template<typename T>
// using u_set = std::unordered_set<T>;

// template<typename Key, typename Value>
// using u_map = std::unordered_map<Key, Value>;
// #define mii map<int, int>
// #define umii u_map<int, int>
using namespace std;
const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;




void solve() {
    int n,k,h;
    cin>>n>>k>>h;
    int ans = 0;
    if(n > h){
        ans += (n-h+1)*n;
    }
    
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define loop(i,a,b) std::(int i=a;i<b;i++)
#define rloop(i,a,b) std::for(int i=a;i>=b;i--)
#define rep(i,n) rep(i,0,n)
#define el cout<<endl;
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define cin(a) int a;cin>>a;
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define input(a) for(int j=0;j<a.size();j++) cin>>a[j];
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

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if(i*i != n)
                factors.push_back(n/i);
        }
    }
    return factors;
}

long long binpow(long long a, long long b, long long m = M) {//a**b%m
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n;
    cin>>n;
    vi a(n);
    input(a)
    unordered_set<int>st;
    for(auto it: a)
        st.insert(it);
    int sz = st.size();
    cout<<sz<<endl;
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
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define loop(i,a,b) std::(int i=a;i<b;i++)
#define rloop(i,a,b) std::for(int i=a;i>=b;i--)
#define rep(i,n) rep(i,0,n)
#define enl cout<<endl
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define cin(a) int a;cin>>a
#define precise(i) cout<<fixed<<setprecision(i)
#define vi vector<int>
#define input(a) for(int j=0;j<a.size();j++) cin>>a[j];
#define debug(a) for(int j=0;j<a.size();j++) cout<<a[j]<<' ';cout<<endl
#define dbg(x) cout << #x << " = " << x << endl
#define vpii vector<pair<int,int>>
#define sis string s;
#define sin string s;cin>>s
#define db double
#define sz(x) static_cast<int>((x).size())
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define pub push_back
#define pob pop_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define bpc(x) __builtin_popcntll(x);
#define ctz(x) __builtin_ctz(x);//cnts tailing zeros
// template<typename T>
// using u_set = std::unordered_set<T>;
 
// template<typename Key, typename Value>
// using u_map = std::unordered_map<Key, Value>;
// #define mii map<int, int>
// #define umii u_map<int, int>
const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;

long long power(long long a,long long b){
    long long ret=1;
    while(b){
        if(b&1)ret*=a;
        if(M)ret%=M;
        b >>= 1;
        a *= a;
        if(M)
            a%=M;
    }
    if(M)
        ret%=M;
    return ret;
}


long long MInverse(long long a) {
    long long result = 1;
    long long p = M - 2;
    while (p) {
        if (p % 2 == 1) {
            result = (result * a) % M;
        }
        a = (a * a) % M;
        p /= 2;
    }
    return result;
}

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void solve(){
    int n;
    cin>>n;
    vi a(n+20), sum(n+20);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        sum[i] = (sum[i+1]+a[i])%M;
    }

    int ans=0;
    for(int i=1;i<=n;i++){
        ans = (ans + a[i]*sum[i+1])%M;
    }
    
    int res = (int)n*(n-1)/2;
    res = power(res,M-2);
    ans = 1LL*ans*res;
    ans %= M;
    cout<<ans-1<<endl;
}


 
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
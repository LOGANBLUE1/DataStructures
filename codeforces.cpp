#include <bits/stdc++.h>
#define ll long long
#define int long long
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
    int n,k;
    cin>>n>>k;
    vi a(n), b(n);
    for(int i=0;i<n;i++)
        cin>>a[i]>>b[i];
    int val = accumulate(all(a),0LL) + accumulate(all(b),0LL);
    if(val < k){
        cout<<-1<<endl;
        return;
    }
    vector<pair<int,int> >v;
    for(int i=0;i<n;i++){
        v.push_back(make_pair(min(a[i],b[i]),i));
    }
    sort(v.begin(),v.end());
    int ans = 0;
    for(int i=0;i<v.size() && k;i++){
        int ind = v[i].second;
        int x = a[ind], y = b[ind];
        if(x+y <= k){
            ans += x*y;
            k -= x+y;
        }
        else{
            for(int i=0;i<k;i++){
                ans += min(x,y);
                if(x>=y)
                    x--;
                else    
                    y--;
            }
            k=0;
        }
        cout<<ans<<' '<<k<<"  ";
    }
    cout<<ans<<endl;
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
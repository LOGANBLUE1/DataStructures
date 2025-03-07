#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define ff first
#define ss second

const long long INF = 1e18;
const long long M = 1e9+7;


void solve() {
    int n;
    string a,b;
    cin >> n >> a >> b;
    int ans = count(all(a), '1') + count(all(b), '1');
    if((n%2==0 && ans&1)||(a==b && (ans/2)&1 && n%2==0)){
        cout << "NO\n";
        return;
    }
    else{
        cout<<"YES\n";
    }
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

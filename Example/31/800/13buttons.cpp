#include <bits/stdc++.h>
using namespace std;
const long long INF=1e18;
const long long M=1e9+7;
const long long MM=998244353;


void solve() {
    int a,b,c;
    cin>>a>>b>>c;
    if(b+c < a)
        cout<<"First"<<endl;
    else if(a+c <= b)
        cout<<"Second"<<endl;
    else{
        if(c&1){
            if(b > a)
                cout<<"Second"<<endl;
            else
                cout<<"First"<<endl;
        }
        else{
            if(b >= a)
                cout<<"Second"<<endl;
            else
                cout<<"First"<<endl;
        }
    }
}




signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL)co;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
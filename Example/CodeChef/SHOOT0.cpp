#include<bits/stdc++.h>
using namespace std;

void solve() {
    int r,c;
    cin >> r>>c;
    vector<int> v(c);
    for(int i=0;i<c;i++){
        cin>>v[i];
    }
    vector<int> a(c), b(c);
    a[0] = (v[0]==1||v[0]==3);
    b[0] = (v[0]==2||v[0]==3);
    for(int i=1;i<c;i++){
        a[i] = a[i-1] + (v[i]==1||v[i]==3);
        b[i] = b[i-1] + (v[i]==2||v[i]==3);
    }
    int sum1 = 0, sum2 = 0;//for x=0
    for(int i=0;i<c;i++){
        if(v[i]==1||v[i]==3)
            sum1 += i;
        if(v[i]==2||v[i]==3)
            sum2 += i;
    }
    cout<<abs(sum1-sum2)<<" ";
    
    for(int i=1;i<c;i++){//for x=1 to c-1
        sum1 += a[i-1];
        sum1 -= (a[c-1]-a[i-1]);
        
        sum2 += b[i-1];
        sum2 -= (b[c-1]-b[i-1]);
        cout<<abs(sum1-sum2)<<" ";
    }
    cout<<endl;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    //cin>>t;
    for(int i = 0; i < t; i++){
        solve();
    }
    return 0;
}
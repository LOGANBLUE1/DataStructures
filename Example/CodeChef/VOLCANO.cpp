#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,p;
    cin>>n>>p;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<> > pq;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++) {
        if(a[i]==0){
            pq.push({0, i});
            ans[i] = 0;
        }
    }
    while (!pq.empty()) {
        auto [val, idx] = pq.top(); pq.pop();

        for (int d : {-1, 1}) {
            int ni = idx + d;
            if (ni < 0 || ni >= n || ans[ni] != -1) continue;

            ans[ni] = max(val, a[ni]);
            pq.push({ans[ni], ni});
        }
    }
    for(int i=0;i<n;i++) 
        cout<<(ans[i]+p-1)/p<<" ";
    cout<<endl;
}
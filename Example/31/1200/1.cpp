// https://codeforces.com/problemset/problem/1914/D
void solve(){
    int n, k;
    cin>>n;
    vpii a(n), b(n), c(n);
    for(int i=0;i<n;i++){
        cin>>k;
        a[i] = {k, i};
    }
    for(int i=0;i<n;i++){
        cin>>k;
        b[i] = {k, i};
    }
    for(int i=0;i<n;i++){
        cin>>k;
        c[i] = {k, i};
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    vpii x, y, z;
    for(int i=n-1;i>=n-3;i--){
        x.push_back(a[i]);
        y.push_back(b[i]);
        z.push_back(c[i]);
    }
    int ans = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                if((x[i].ss != y[j].ss) && (x[i].ss != z[k].ss) && (y[j].ss != z[k].ss)){
                    ans = max(ans, x[i].ff + y[j].ff + z[k].ff);
                }
            }
        }
    }
    cout<<ans<<endl;
}

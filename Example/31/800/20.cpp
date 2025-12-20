// https://codeforces.com/problemset/problem/1831/A

void solve(){
    int n, k;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cout<<n+1-a[i]<<" ";
    }cout<<endl;
}

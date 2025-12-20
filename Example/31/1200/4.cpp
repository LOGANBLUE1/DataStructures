// https://codeforces.com/problemset/problem/1857/C

void solve(){
    int n;
    cin>>n;
    vi a(nc2(n)), b(n);
    for(int i=0;i<nc2(n);i++){
        cin>>a[i];
    }
    sort(all(a));

    int x = n - 1, i = 0;
    while (x > 0) {
        cout << a[i] << " ";
        i += x;
        x--;
    }
    cout << "1000000000\n";
}

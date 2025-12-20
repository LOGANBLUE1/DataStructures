// https://codeforces.com/problemset/problem/1828/B

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int k = abs(a[0] - 1);
    for (int i = 1; i < n; i++){
        k = gcd(k, abs(a[i] - (i + 1)));
    }
    cout << k << endl;
}
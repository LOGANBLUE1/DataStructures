// https://codeforces.com/problemset/problem/1891/B
void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n), x(q);
    for (int i = 0; i < n; i++) { 
        cin >> a[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> x[i];
    }

    int prev = 31;
    for (int i = 0; i < q; i++) {
        if (x[i] >= prev) continue;

        int val = pow(2, x[i]);

        for (int j = 0; j < n; j++) {
            if (a[j] % val == 0) {
                a[j] += (val / 2);
            }
        }

        prev = x[i];
    }

    print(a);
}
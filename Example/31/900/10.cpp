// https://codeforces.com/problemset/problem/1807/D

void solve(){
    int n, q;
    cin >> n >> q;
    vi a(n), pref(n);
    for(int i=0;i<a.size();i++){
        cin>>a[i];
        pref[i] = (a[i] + (i>0 ? pref[i-1]: 0))%2;
    }
    bool isOdd = pref[n-1]&1;
    int l, r, k;
    for(int i=0;i<q;i++){
        cin >> l >> r >> k;
        l--,r--;
        int sum = k*(r-l+1);
        int sub = pref[r] - (l-1 >= 0 ? pref[l-1]: 0);
        sum -= sub;
        printYesNo((sum&1)^isOdd);
    }
}
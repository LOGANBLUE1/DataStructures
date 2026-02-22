// https://codeforces.com/problemset/problem/1665/B

void solve() {
    int n;
    cin>>n;
    vi a(n);
    input(a);
    map<int,int> freq;
    for (int i=0;i<n;i++) freq[a[i]]++;
    int maxFreq = 0;
    for (auto i:freq) maxFreq = max(maxFreq, i.ss);
    int ans = 0;
    while (maxFreq < n){
        ans++;// for cloning
        ans += min(maxFreq, n - maxFreq);
        maxFreq *= 2;
    }

    cout << ans << endl; 
}

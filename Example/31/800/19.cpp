void solve(){
    int n;
    cin>>n;
    vi a(n);
    input(a);
    int pos = count(a.begin(), a.end(), 1), neg = n-pos, ans = 0;
    if(neg&1) neg--,pos++,ans++;
    if(neg > pos){
        int x = (neg-pos + 1) / 2;
        if (x & 1) x++;
        ans += x;
    }
    cout<<ans<<endl;
}
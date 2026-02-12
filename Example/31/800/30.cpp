// https://codeforces.com/problemset/problem/1766/A

void solve(){
    int n;
    cin>>n;
    string s = to_string(n);
    int ans = s[0]-'0';
    ans += 9*(s.size()-1);
    cout<<ans<<endl;
}
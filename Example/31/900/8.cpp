// https://codeforces.com/problemset/problem/1837/B
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cnt = 1, ans = 0;
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])
            cnt++;
        else{
            ans = max(ans, cnt), cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout<<ans+1<<endl;
}

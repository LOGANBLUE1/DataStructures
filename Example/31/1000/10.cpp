// https://codeforces.com/problemset/problem/1744/C

void solve(){
    int n;char ch;string s;
    cin >> n >> ch >> s;
    s += s;
    int prev = -1, cnt = 0, ans = 0;
    for(int i=2*n;i>=0;i--){
        if(s[i]=='g'){
            prev = i;
        }
        if(s[i]==ch){
            if(prev != -1)
                ans = max(ans, prev-i);
        }
    }
    cout<<ans<<endl;
}

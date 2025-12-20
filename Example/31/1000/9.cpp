// https://codeforces.com/problemset/problem/1765/M

void solve(){
    int n;
    cin >> n;
    for(int i=2; i*i<=n; i++){
        if(n%i == 0){
            cout<<n/i<<" "<<n-n/i<<endl;
            return;
        }
    }
    cout<<1<<" "<<n-1<<endl;
}

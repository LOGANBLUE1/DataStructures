// https://codeforces.com/problemset/problem/1927/D


void solve(){
    int n;
    cin>>n;
    vi a(n), prev(n);
    input(a);
    int prv = -1;
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1])
            prv = i-1;
        prev[i] = prv;
    }
    debug(prev);
    int q;
    cin>>q;
    int l,r;
    for(int i=0;i<q;i++){
        cin>>l>>r;
        l--,r--;
        if(prev[r] >= l)
            cout<<prev[r]+1<<" "<<r+1<<endl;
        else    
            cout<<-1<<" "<<-1<<endl;
    }
    cout<<endl;
}
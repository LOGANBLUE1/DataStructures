// https://codeforces.com/problemset/problem/1806/A

void solve(){
    int n;
    pii a, b, diff;
    cin>>a.ff>>a.ss>>b.ff>>b.ss;
    diff.ff = b.ff-a.ff, diff.ss = b.ss-a.ss;
    if(diff.ss < 0 || diff.ss < diff.ff){
        cout<<-1<<endl;
        return;
    }
    else{
        cout<<diff.ss + (diff.ss-diff.ff)<<endl;
    }
}
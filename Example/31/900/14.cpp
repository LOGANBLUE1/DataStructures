// https://codeforces.com/problemset/problem/1679/A

void solve() {
    int n;
    cin >> n;
    if(n&1 || n<=2){
        cout<<-1<<endl;
    }
    else{
        int six = n/6, four = n/4;
        if(six*6 < n)
            six++;
        cout<<six<<" "<<four<<endl;
    }
}
// https://codeforces.com/problemset/problem/1931/E

int getNoOfDigit(int n){
    return log10(n)+1;
}

int getReverseInt(int a){
    string s = to_string(a);
    reverse(all(s));
    return stoi(s);
}

void solve(){
    int n, m;
    cin>>n >> m;
    vi a(n);
    input(a);
    int ans = 0;
    vector<int>rem;
    for(auto i: a){
        int dig = getNoOfDigit(i), rev = getNoOfDigit(getReverseInt(i));
        if(rev != getNoOfDigit(i))
            rem.pb(dig-rev);
        ans += rev;
    }
    sort(rem.rbegin(), rem.rend());
    for(int i=1;i<rem.size();i+=2){
        ans += rem[i];
    }
    if(ans-1 < m){
        cout<<"Anna"<<endl;
    }
    else{
        cout<<"Sasha"<<endl;
    }
}
// https://codeforces.com/problemset/problem/1814/A

void solve(){
    int n, k;
    cin>>n >> k;
    printYesNo(!(n&1 && k%2==0));
}
// https://codeforces.com/problemset/problem/1872/D

int sum(int a){
    return a*(a+1)/2;
}

void solve(){
    int n, x, y;
    cin >> n >> x >> y;//cx- 2 4 6 8 10, cy - 3 6 9, cc - 6
    int cc = n*gcd(x, y)/x/y, cx = n/x-cc, cy = n/y-cc;
    //   sum of x          - sum y
    cout<<(sum(n)-sum(n-cx))-sum(cy)<<endl;
}

// https://codeforces.com/problemset/problem/1873/E

int pred(vi &a, int mid){
    int ans = 0;
    for(auto i: a){
        ans += max(0, mid-i);
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vi a(n);
    input(a);
    int s = 1, e = 1e12, ans = -1;
    while(s <= e){
        int mid = s + (e-s)/2;
        if(pred(a, mid) <= k){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    cout<<ans<<endl;
}
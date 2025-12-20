// https://codeforces.com/problemset/problem/1909/B

void solve(){
    int n;
    cin >> n;
    vi a(n);
    input(a);
    int ans = 0;
    for (int i = 1; i <= 60; i++) { 
        set<int> st;
        int k = 1LL << i;
        dbg(k);
        for (int ind = 0; ind < n; ind++) {
            st.insert(a[ind] % k);
            cerr<<a[ind] % k<<" ";
        }cerr<<endl;
        if (st.size() == 2) {
            ans = k;
            break;
        }
    }
    cout << ans << endl;
}

// let say there is any array of any length
//rem with k=1 for all element will be only 0 -> 1 distinct
//rem with k=2 for all element will be only 0 or 1 -> atmost 2 distinct
// ...
//if rem with k=2 for all element is same e.g. 0 
// -> try with 4 it can be 0, 2, if not two diff rems
// -> try with 8 it can be two others and at some point there will be two remainders

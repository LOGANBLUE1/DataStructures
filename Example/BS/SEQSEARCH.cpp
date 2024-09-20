void solve(){
    init(a);
    init(b);
    init(k);

    if (k == 1){
        out("0\n");
        return;
    }
    k--;

    //  a b a+b 2b a+2b 3b a+3b 4b a+4b 5b a+5b

    ll l = 0, r = 1e18, ans = -1;
    while (l <= r){
        ll mid = (l + r) / 2; // (l+r)>>1

        ll tot_terms = mid / b;
        if (mid - a >= 0){
            tot_terms += (mid - a) / b + 1;
        }

        if (tot_terms >= k){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }
    cout<<ans<<endl;
}
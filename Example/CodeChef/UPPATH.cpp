// https://www.codechef.com/problems/UPPATH?tab=statement


void solve(){
    int n;
    cin>>n;
    vvi a(2, vi(n));
    for(int i=0;i<n;i++){
        cin>>a[0][i];
    }
    for(int i=0;i<n;i++){
        cin>>a[1][i];
    }
    vi minPref(n), maxSuff(n);
    minPref[0] = min(a[0][0], a[1][0]);
    maxSuff[n-1] = max(a[0][n-1], a[1][n-1]);
    for(int i=1;i<n;i++){
        int mi = min(a[0][i], a[1][i]), ma = max(a[0][i], a[1][i]);
        if(ma < minPref[i-1]){
            cout<<"No"<<endl;
            return;
        }
        minPref[i] = (mi >= minPref[i-1]) ? mi : ma;
    }
    for(int i=n-2;i>=0;i--){
        int mi = min(a[0][i], a[1][i]), ma = max(a[0][i], a[1][i]);
        if(mi > maxSuff[i+1]){
            cout<<"NO"<<endl;
            return;
        }
        maxSuff[i] = (ma <= maxSuff[i+1]) ? ma : mi;
    }
    int mi = min(a[0][0], a[1][0]), ma = max(a[0][0], a[1][0]);
    if(ma >= mi && ma <= maxSuff[1]){
        cout<<"Yes"<<endl;
        return;
    }
    for(int i=1;i<n-1;i++){
        int mi = min(a[0][i], a[1][i]), ma = max(a[0][i], a[1][i]);
        if(maxSuff[i+1] >= ma && ma >= mi && mi >= minPref[i-1]){
            cout<<"Yes"<<endl;
            return;
        }
    }
    {
        int mi = min(a[0][n-1], a[1][n-1]);
        int ma = max(a[0][n-1], a[1][n-1]);
        if(mi >= minPref[n-2] && ma >= mi){
            cout<<"Yes"<<endl;
            return;
        }
    }
    cout<<"No"<<endl;
}
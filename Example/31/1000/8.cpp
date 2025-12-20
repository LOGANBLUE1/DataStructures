// https://codeforces.com/problemset/problem/1791/D

int findVal(vector<int>&a){
    int cnt = 0;
    for(auto i:a)if(i)cnt++;
    return cnt;
}
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int>a(26), curr(26);
    for(auto i: s)a[i-'a']++;

    int ans = 0;
    for(int i=0;i<n-1;i++){
        char ch = s[i];
        a[ch-'a']--;
        curr[ch-'a']++;
        ans = max(ans, findVal(a)+findVal(curr));
    }
    cout<<ans<<endl;
}
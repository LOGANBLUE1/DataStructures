void solve(){
    int n;
    string s;
    cin>>n>>s;
    unordered_set<char>st;
    int ans = 0;
    for(char c: s){
        st.insert(c);
        ans += st.size();// unique substrings with length 5, 4, 3 ... 
    }
    // 1 substring of length n
    // 2 substrings of length n-1 if second char is different from first
    cout<<ans<<endl;
}
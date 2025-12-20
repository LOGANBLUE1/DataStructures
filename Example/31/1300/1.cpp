// https://codeforces.com/problemset/problem/1931/D

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    vi a(n);
    input(a);
    map<int, map<int, int>> mp;
    
    for (int i: a) {
        mp[i % y][i % x]++;
    }
 
    int ans = 0;
    for (auto [_, mp1] : mp) {

        for (auto [r1, c] : mp1) {
            if (r1 == 0 || (r1 == x / 2 && x % 2 == 0)) {
                ans += nc2(c);
            } else {
                ans += c * mp1[x - r1];
                mp1[x - r1] = 0;
            }
        }
    }
    cout << ans << endl;
}

#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define ff first
#define ss second
std::mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const long long M = 1e9+7;
int MOD = 998244353;
long long computeModInverse(long long base) {
    long long result = 1, exp = M - 2;
    while (exp) {
        if (exp % 2) result = (result * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return result;
}

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

long long mod_pow(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void bruteForce(int n, vector<int>&a){
    for(int i=0;i<(1<<n);i++){
        for(int i=0;i<32;i++){
            
        }
    }
}

tuple<int,int,int> getMaxSum(const vector<int>&arr){
    int n = arr.size();
    int maxSum = arr[0], currSum = 0;
    int l = 0, r = 0, l2 = 0, r2 = 0;
    for(int i=0;i<n;i++){
        currSum += arr[i];
        if(currSum > maxSum){
            maxSum = currSum;
            l = l2, r = i;
        }
        if(currSum < 0){
            currSum = 0;
            l2 = i+1, r2 = i+1;
        }
    }
    return {l, r, maxSum};
}

int findSum(vector<int>&a, vector<int>&b, int x, int y){
    cout<<x<<" - "<<y<<endl;
    int len = y-x+1;
    vector<int>pref(len);
    pref[0] = a[x];
    for(int i=1;i<len;i++){
        pref[i] = pref[i-1] + a[x+i];
    }
    int curr = b[y]+pref[y-x], maxAns = curr;
    for(int i=y-1;i>=x;i--){
        curr += b[i]-a[i];
        maxAns = max(maxAns, curr+pref[i-x]);
    }
    return maxAns;
}

// void solve2() {
//     int n;
//     cin>>n;
//     vector<int>a(n), b(n);
//     for(int i=0;i<n;i++){
//         cin>>a[i];
//     }
//     for(int i=0;i<n;i++){
//         cin>>b[i];
//     }
//     auto [l,r,s] = getMaxSum(a);
//     auto [l2, r2, s2] = getMaxSum(b);
//     if((r>=l2 && r<=r2)||(l>=l2 && l<=r2)){
//         cout<<s+s2<<endl;
//     }
//     else{
//         int ans;
//         if(l < l2)  ans = findSum(a, b, r, l2);
//         else    ans = findSum(b, a, r2, l);
//         cout<<ans<<endl;
//     }
// }

void solve(){
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int cnt = 0, i=0, ans = 0;
    for(;i<n&&s[i]=='0';i++,ans++){}
    for(;i<n;i++){
        if(s[i]=='0'){
            cnt++;
        }
        else{
            ans += max(0LL, cnt - k);
            cnt = 0;
        }
    }
    ans += max(0LL, cnt - k);
    cout<<ans<<endl;
}

int solve(vector<int>&a, vector<int>&b, int idx, vector<int>&dp){
    if(idx < 0) return 0;
    if(dp[idx] != -1) return dp[idx];
    int takeA = solve(a, b, idx-1, dp) - a[idx];
    int takeB = -1*(solve(a, b, idx-1, dp) - b[idx]);
    return dp[idx] = max(takeA, takeB);
}

void solve(){
    int n;
    cin>>n;
    vi a(n), b(n);
    vector<int>dp(n+1, -1);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];

    cout<<solve(a, b, n-1, dp)<<" ";
}

void printYesNo(bool cond){
    cout<<(cond ? "Yes": "No")<<endl;
}
signed main(){  
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}


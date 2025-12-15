#include <bits/stdc++.h>
#include <chrono>
#include <random>
using namespace std;
#define int long long
#define ll long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define vi vector<int>
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define ff first
#define ss second
std::mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const long long M = 1e9+7;
const long long MOD = 998244353;

void print(int a){
    cout<<a<<" ";
}
void print(vector<int>&a){
    for (auto i:a) cout<<i<<" ";
    cout<<endl;
}
void print(vector<vector<int>>&a){
    for (auto i:a){
        for (auto j:i) cout<<j<<" ";
        cout<<endl;
    }
}
void print(set<int>&s){
    for (auto i:s) cout<<i<<" ";
    cout<<endl;
}
void print(map<int,int>&m){
    for (auto i:m) cout<<i.ff<<":"<<i.ss<<" ";
    cout<<endl;
}
void print(pair<int,int>&p){
    cout<<"{"<<p.ff<<","<<p.ss<<"}"<<endl;
}
void print(vector<pii>&a){
    for (auto i:a) cout<<"{"<<i.ff<<","<<i.ss<<"} ";
    cout<<endl;
}
void print(vector<vector<pii>>&a){
    for (auto i:a){
        for (auto j:i) cout<<"{"<<j.ff<<","<<j.ss<<"} ";
        cout<<endl;
    }
}
void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void print(stack<int>s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
void print(deque<int>d){
    for (auto i:d) cout<<i<<" ";
    cout<<endl;
}
void print(priority_queue<int>pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}

long long computeModInverse(long long base) {
    long long result = 1, exp = M - 2;
    while (exp) {
        if (exp % 2) result = (result * base) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return result;
}

vector<int> getPref(vector<int>&a){
    vector<int> pref(a.size()+1);
    for (int i = 1; i <= a.size(); i++){
        pref[i] = (pref[i-1] + a[i-1]);
    }
    return pref;// 0 a[0] a[0]+a[1]
}

vector<int> getSuff(vector<int>&a){
    vector<int> suff(a.size()+1);
    for (int i = a.size()-1; i >= 0; i--){
        suff[i] = (suff[i+1] + a[i-1]);
    }
    return suff;
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

long long modPow(long long base, long long exp, long long mod) {
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

bool isCorrect(string tobe, string given){
    for(int i=0;i<tobe.size();i++){
        if(tobe[i]=='1' && given[i]=='0') return false;
    }
    return true;
}

// unordered_map<int, unordered_map<int, int>> dp;
// int n;
// int solveRec(int prodLeft, int minFactor, int sumLeft) {
//     if (sumLeft < 0) return 0;
//     if (prodLeft < minFactor) return 0;

//     if (dp[prodLeft].count(minFactor))
//         return dp[prodLeft][minFactor];

//     int ways = 0;
//     if (prodLeft <= sumLeft) ways++;

//     int lim = sqrtl(prodLeft);
//     for (int f = minFactor; f <= lim; ++f) {
//         if (prodLeft % f == 0) {
//             if (f > sumLeft) break;
//             ways += solveRec(prodLeft / f, f, sumLeft - f);
//         }
//     }

//     return dp[prodLeft][minFactor] = ways;
// }

void solve(){
    // cin >> n;
    // if (n == 1) {
    //     cout << 1 << '\n';
    //     return;
    // }
    // dp.clear();
    // cout << solveRec(n, 2, n) << '\n';
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) // n
        cin >> a[i];
    vector<int> b(n);
    for (int i = 0; i < n; i++) // n
        cin >> b[i];

    unordered_map<int,int> freq_a, freq_b;

    int cnt = 1;
    for (int i = 1; i < n; i++){
        if (a[i] == a[i - 1])
            cnt++;
        else{
            freq_a[a[i - 1]] = max(freq_a[a[i - 1]], cnt);
            cnt = 1;
        }
    }
    freq_a[a[n - 1]] = max(freq_a[a[n - 1]], cnt);

    cnt = 1;
    for (int i = 1; i < n; i++){
        if (b[i] == b[i - 1])
            cnt++;
        else{
            freq_b[b[i - 1]] = max(freq_b[b[i - 1]], cnt);
            cnt = 1;
        }
    }
    freq_b[b[n - 1]] = max(freq_b[b[n - 1]], cnt);

    int max_freq = -1;
    for (int i = 1; i <= 2 * n; i++)
        max_freq = max(max_freq, freq_a[i] + freq_b[i]);

    cout << max_freq << endl;
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


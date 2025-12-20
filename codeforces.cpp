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
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define all(x) begin(x), end(x)
#define ff first
#define ss second
#define dbg(x) cerr << #x << "=" << x << " "
#define dbgln(x) cerr << #x << "=" << x << "\n"
#define input(a) for(int i=0;i<a.size();i++)cin>>a[i]
std::mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e18;
const long long M = 1e9+7;
const long long MOD = 998244353;

void print(int a){
    cerr<<a<<" ";
}
void debug(vector<int>&a){
    for (auto i:a) cerr<<i<<" ";
    cerr<<endl;
}
void print(vector<int>&a){
    for (auto i:a) cout<<i<<" ";
    cout<<endl;
}
void print(vector<vector<int>>&a){
    for (int i=0;i<a.size();i++){
        dbg(i);
        for (auto j:a[i]) cerr<<j<<" ";
        cerr<<endl;
    }
}
void print(set<int>&s){
    for (auto i:s) cerr<<i<<" ";
    cerr<<endl;
}
void print(map<int,int>&m){
    for (auto i:m) cerr<<i.ff<<":"<<i.ss<<" ";
    cerr<<endl;
}
void print(pair<int,int>&p){
    cerr<<"{"<<p.ff<<","<<p.ss<<"} ";
}
void print(vector<pii>&a){
    for (auto i:a) cerr<<"{"<<i.ff<<","<<i.ss<<"} ";
    cerr<<endl;
}
void print(vector<vector<pii>>&a){
    for (auto i:a){
        for (auto j:i) cerr<<"{"<<j.ff<<","<<j.ss<<"} ";
        cerr<<endl;
    }
}
void print(queue<int>q){
    while(!q.empty()){
        cerr<<q.front()<<" ";
        q.pop();
    }
    cerr<<endl;
}
void print(stack<int>s){
    while(!s.empty()){
        cerr<<s.top()<<" ";
        s.pop();
    }
    cerr<<endl;
}
void print(deque<int>d){
    for (auto i:d) cerr<<i<<" ";
    cerr<<endl;
}
void print(priority_queue<int>pq){
    while(!pq.empty()){
        cerr<<pq.top()<<" ";
        pq.pop();
    }
    cerr<<endl;
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

int modPow(int base, int exp, int mod) {
    int result = 1;
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

inline int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a % b);
}
inline int max(int a, int32_t b){
    return max(a, 1LL*b);
}
inline int max(int32_t a, int b){
    return max(1LL*a, b);
}

void printYesNo(bool cond){
    cout<<(cond ? "YES": "NO")<<endl;
}

int pre(vi &a, vi &b, int mid){
    int y = mid;
    for(int i=0;i<a.size();i++){
        y = max(a[i], b[i]+y);
    }
    return y;
}


int sum(int a){
    return a*(a+1)/2;
}
int nc2(int n){
    return n*(n-1)/2;
}

int pred(vi &a, int mid){
    int ans = 0;
    for(auto i: a){

    }
    return ans;
}

int dist(pii &a, pii &b){
    return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}
pii makep(int a, int b){
    return make_pair(a, b);
}

void solve(){
    int n, m;
    cin>>n >> m;
    vi a(n);
    input(a);
    
}

signed main(){  
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << " ms.\n"; 
    return 0;
}


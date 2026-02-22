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
#define rall(x) rbegin(x), rend(x)
#define ff first
#define ss second
#define dbg(x) cerr << #x << "=" << x << " "
#define dbgln(x) cerr << #x << "=" << x << "\n"
#define input(a) for(int i=0;i<a.size();i++) cin>>a[i]
std::mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// __builtin_popcount(num)
const long long INF = 1e18;
const long long M = 1e9+7;
const long long MOD = 998244353;
template<class T>
void print(T a){
    cerr<<a<<" ";
}
template<class T>
void debug(const vector<T>& a){
    for(const auto& i : a) cerr << i << " ";
    cerr << '\n';
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
int getNoOfDigit(int n){
    return log10(n)+1;
}

int computeModInverse(int base) {
    int result = 1, exp = M - 2;
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

int dist(pii &a, pii &b){
    return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

int getReverseInt(int a){
    string s = to_string(a);
    reverse(all(s));
    return stoi(s);
}

bitset<32> getBitset(int n){//to print 6 -> 01100000....
    bitset<32> a(n);
    return a;
}

int getMinDiff(vector<int>&a){
    int res = 1e9;
    for(int i=1;i<a.size();i++){
        res = min(res, a[i]-a[i-1]);
    }
    return res;
}

void solve2(){
    int A,B;
    cin>>A>>B;
    vi a(A), b(B);
    for(int i=0;i<A;i++) cin>>a[i];
    for(int i=0;i<B;i++) cin>>b[i];
    sort(all(a));
    sort(all(b));
    vi maxPrefA(A,0), maxPrefB(B,0), maxSuffA(A,0), maxSuffB(B,0);
    //  1->A-1           1->B-1             A-2->0            B-2->0
    for(int i=1;i<A;i++) maxPrefA[i] = max(maxPrefA[i-1], (a[i]-a[i-1]));
    for(int i=1;i<B;i++) maxPrefB[i] = max(maxPrefB[i-1], (b[i]-b[i-1]));
    for(int i=A-2;i>=0;i--) maxSuffA[i] = max(maxSuffA[i+1], (a[i+1]-a[i]));
    for(int i=B-2;i>=0;i--) maxSuffB[i] = max(maxSuffB[i+1], (b[i+1]-b[i]));

}

vector<int> fact;
void initFactorial()
{
    int n = 2e5+5;
    fact.resize(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(2*b == a+c) printYesNo(true);
    else if((((2*b - c > 0) && (2*b - c)%a == 0)) || ((2*b - a > 0) && (2*b - a)%c == 0) || (a+c)%(2*b) == 0) printYesNo(true);
    else printYesNo(false);
}

// >= cm         - 2.849
// >= expert     - 8.309
// >= specialist - 16.310
// >= pupil      - 29.212
signed main(){  
    auto begin = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    // initFactorial();
    while(t--){
        solve();
    }
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = chrono::duration_cast<chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-6 << " ms.\n"; 
    return 0;
}


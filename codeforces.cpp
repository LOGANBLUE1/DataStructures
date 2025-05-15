#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define all(x) begin(x), end(x)
#define ff first
#define ss second
vector<int> fact;

const long long INF = 1e18;
const long long M = 1e9+7;

long long computeModInverse(long long base) {
    long long result = 1, exp = M - 2;
    while (exp) {
        if (exp % 2) result = (result * base) % M;
        base = (base * base) % M;
        exp /= 2; 
    }
    return result;
}

long long binpow(long long a, long long b) {//a**b%m
    a %= M;
    long long res = 1;
    while (b > 0) {
        if (b & 1)  res = res * a % M;
        a = a * a % M, b >>= 1;
    }
    return res;
}

int gcd(int a, int b){
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int lcm(int a, int b){
    return ((a / gcd(a, b)) * b);
}

int inversemod(int a){
    return binpow(a, M - 2, M);
}

int divmod(int a, int b){
    return ((a % M) * inversemod(b)) % M;
}

int combination(int n, int k){
    if (k > n)
        return 0;
    int p1 = (fact[n] * inversemod(fact[k])) % M;
    int p2 = (1 * inversemod(fact[n - k])) % M;
    return (p1 * p2) % M;
}

void solve() {
    int n,k;
    cin >> n >> k;
}   

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// Given vector of pair sort in order EE < EO < OE < OO
// eg. vector<pair<int,int>>arr = {{1,8},{7,7},{5,6},{2,3},{6,10},{4,1}};
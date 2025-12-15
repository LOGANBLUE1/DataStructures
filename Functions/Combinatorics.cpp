#include<bits/stdc++.h>
using namespace std;
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

vector<int> getFactorials(int n){
    vector<int> fact(n+1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++){
        fact[i] = (1ll * i * fact[i-1])%M;
    }
    return fact;
}

vector<int> getNCR(int n){
    vector<int> fact = getFactorials(n);
    vector<int> ans(n+1);
    ans[0] = ans[n] = 1;
    for (int i = 1; i < n; i++){
        int val = (1LL * fact[i] * fact[n-i])%M;
        int temp = (1LL * fact[n] * computeModInverse(val))%M;
        ans[i] = temp;
    }
    return ans;
}

int getNCR(int n, int r){
    if(r>n)return 0;
    vector<int> fact = getFactorials(n);
    int val = (1LL * fact[r] * fact[n - r]) % M;
    int temp = (1LL * fact[n] * computeModInverse(val)) % M;
    return temp;
}

long long C(long long n, long long r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invfact[r] % MOD * invfact[n-r] % MOD;
}

int main()
{
    cout<<getNCR(4, 2);

    long long fact[MAX+1], invfact[MAX+1];
    fact[0] = 1;
    for (int i=1; i<=MAX; i++) fact[i] = (fact[i-1] * i) % MOD;
    invfact[MAX] = modpow(fact[MAX], MOD-2);
    for (int i=MAX; i>0; i--) invfact[i-1] = (invfact[i] * i) % MOD;

    return 0;
}
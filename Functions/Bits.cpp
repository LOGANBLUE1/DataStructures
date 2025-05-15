#include<iostream>
using namespace std;
const long long M = 1e9+7;

int a(int num){
    return __builtin_popcount(num);
}

// k -> size of vector
vector<bool> bits(int n,int k){
    vector<bool>ans(k,0);
    for(int i=0;i<k;i++){
        if((n>>i)&1)
            ans[i] = 1;
    }
    return ans;
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

long long val(vector<bool>&a, int k){
    long long ans = 0;
    for(int i=0;i<k;i++){
        if(a[i])
            ans |= 1LL<<i;
    }
    return ans;
}

int firstSetBitNumber(int n){
    return n & -(n); // n & ~(n-1)
}

int firstSetBit(int n){//zero indexed 1 --> 0
    int i = 0;
    for(;!((n>>i)&1);i++){}
    return i;
}

vector<int> getNCR(int n){
    vector<int> fact(n+1);
    fact[1] = 1;
    for (int i = 2; i <= n; i++){
        fact[i] = (1ll * i * fact[i-1])%M;
    }

    vector<int> ans(n+1);
    ans[0] = ans[n] = 1;
    for (int i = 1; i < n; i++){
        int val = (1LL * fact[i] * fact[n-i])%M;
        int temp = (1LL * fact[n] * computeModInverse(val))%M;
        ans[i] = temp;
    }
    
    return ans;
}

int main(){
    int n;
    cin>>n;
    
    return 0;
}
#include<iostream>
using namespace std;

void a(int num){
    __builtin_popcount(num);
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
    int cnt = 0;
    for(;!(n&(1<<(cnt)));cnt++){}
    return cnt;
}

int main(){
    cout<<firstSetBit(1);
    return 0;
}
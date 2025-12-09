#include<iostream>
using namespace std;
const long long M = 1e9+7;

int reverseMeaningfulBits(int n); // 000110 -> 110 -> 011
int reverseAllBits(int x); // 000110 -> 011000... (32 bits)


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

long long val(vector<bool>&a, int k){
    long long ans = 0;
    for(int i=0;i<k;i++){
        if(a[i])
            ans |= 1LL<<i;
    }
    return ans;
}

int reverseMeaningfulBits(int n) { // 000110 -> 11
    int rev = 0;
    while (n > 0) {
        rev = (rev << 1) | (n & 1);
        n >>= 1;
    }
    return rev;
}

int reverseAllBits(int x) {
    int r = 0;
    for (int i = 0; i < 32; i++) {
        r = (r << 1) | (x & 1);
        x >>= 1;
    }
    return r;
}

int firstSetBitNumber(int n){
    return n & -(n); // n & ~(n-1)
    // ~(5) is same as -6
    // ~(0) is same as -1
    // 00000.... -> 11111....
}

int firstSetBit(int n){//zero indexed 1 --> 0
    int i = 0;
    for(;!((n>>i)&1);i++){}
    return i;
}

/// @brief ////////////////// BITSET ////////////////////////////////
void getBitsetPrint(int n){
    // auto a = bitset<32>(n);
    // OR
    bitset<32> a(n);

    // to flip all the bits
    // a.flip();

    //to print 6 -> 01100000....
    for(auto i=0;i<32;i++){
        cout<<a[i]<<" ";
    }

    // convert back to integer
    int x = (int)(a.to_ulong());
}

bitset<32> getBitset(int n){
    bitset<32> a(n);
    return a;
}

int getIntFromBitset(bitset<32>&a){
    return (int)(a.to_ulong());
}

int main(){
    getBitsetPrint(-1);
    return 0;
}
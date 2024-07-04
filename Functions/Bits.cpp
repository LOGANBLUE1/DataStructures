#include<iostream>
using namespace std;


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

int main(){

    return 0;
}
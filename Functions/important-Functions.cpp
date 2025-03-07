#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& a);
vector<int> findFactors(int n);
long long binpow(long long a, long long b, long long mod);
int sumOfDigits(int num);
long long nCr(int n, int r);
bool isPalindrome(int x);
int max(int a,int b,int c);
double power(double x, int n);
long long power(int N, int M);
int bs(vector<int>arr,int s,int e,int target);

int expSearch(vector<int>arr,int n,int x);
bool checkPalindrome(string a);



int lengthOfLIS(vector<int>& a) {
    vector<int>b(1, a[0]);
    for(auto it=a.begin()+1;it<a.end();it++)
        if(*it > b.back())  b.push_back(*it);
        else    b[lower_bound(b.begin(),b.end(),*it) - b.begin()] = *it;
    return b.size();
}

vector<int> findFactors(int n) {
    vector<int> factors;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if(i*i != n)
                factors.push_back(n/i);
        }
    }
    return factors;
}

long long binpow(long long a, long long b, long long m) {//a**b%m
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int sumOfDigits(int num){
    int sum = 0;
    string s = to_string(num);
    for (char digit : s) {
        sum += digit - '0';
    }
    return sum;
}

int sumOfDigits(int num){
    int sum = 0;
    for (;num != 0; num /= 10) {
        sum += num % 10;   
    }
    return sum;
}


long long nCr(int n, int r) {
    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}


bool isPalindrome(int x){
    if(x<0) return false;
    int num = x;
    int rev = 0;
    while(num && rev < INT_MAX/10-1){
        rev = rev*10 + num%10;
        num /= 10;
    }
    return (x == rev);
}


int max(int a,int b,int c){
    if (a >= b && a >= c){
        return a;
    }
    else if (b >= c && b >= c){
        return b;
    }
    return c;
}


double power(double x, int n) {
    double ans = 1.0;
    bool negative = n < 0 ? true : false;
    long long nn = n;
    if(nn < 0)  nn = -nn;
    while (nn) {
        if (nn % 2) {
            ans *= x;
            nn--;
        } 
        else {
            x *= x;
            nn >>= 1;
        }
    }
    return negative ? 1.0/ans : ans;
}


long long power(int N, int pow){
    int sum = 1;
    if(N == 0) sum = 0;
    while(pow > 0){
        if(pow & 1)
            sum *= N;
        N = N * N;
        pow = pow >> 1;
    }
    return sum;
}


bool checkPalindrome(string a) {
    int s = 0;
    int e = a.length()-1;

    while(s<=e) {
        if(a[s] != a[e])
        {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}

int bs(vector<int>arr,int s,int e,int target){
    while(s<=e){
        int mid = (s+e) >>1;
        if( target == arr[mid]){
            return mid;
        }
        else if( target > arr[mid] ){
            s = mid+1;
        }
        else{
            e = mid-1;
        }
    }
    return -1;
}

int expSearch(vector<int>arr,int n,int x){
    if( n == 1)  return 1;

    int i = 1;
    while( i < n && arr[i] <= x ){
       i *= 2;
    }
  return bs(arr,i/2,min(n-1,i),x);
}

//redix sort
void a(){
    int n;
    vector<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    // ranges::stable_sort(idx, [&](auto a, auto b) { return nums[a] < nums[b]; });
}
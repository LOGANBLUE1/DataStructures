#include<bits/stdc++.h>
using namespace std;

int sumOfDigits(int num)
int nCr(int n, int r);
bool isPalindrome(int x);
int max(int a,int b,int c);
double power(double x, int n);
int power(int N, int M);
vector<int> findMissingRepeatingNumbers(vector<int> a);
int expSearch(vector<int>arr,int n,int x);
bool checkPalindrome(string a);





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


int nCr(int n, int r) {
    long long res = 1;

    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
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
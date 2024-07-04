// #include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
using namespace std;

//123 -> 132
// next_permutation(arr,arr+3); 

// bool ans = isequal(a.begin(),a.end(),b.begin(),b.end());
__builtin_popcount(num);
is_sorted(v.begin(), v.end());
count(s.begin(), s.end(), ch);

int sumOfDigits(int num);
long long sum(vector<int>&nums);
int sum(vector<int>&nums);
int frequency(string& s,char ch);
int greatest(vector<int>&arr)
int smallest(vector<int>&arr)


long long sum(vector<int>&nums){
    return accumulate(nums.begin(), nums.end(), 0L);
} 
int sum(vector<int>&nums){
    return accumulate(nums.begin(), nums.end(), 0);
}
int frequency(string& s,char ch){
    return count(s.begin(), s.end(), ch);
}
int greatest(vector<int>&arr){
    return *max_element(arr.begin(),arr.end());
}
int smallest(vector<int>&arr){
    return *min_element(arr.begin(),arr.end());
}


int main(){
    
    return 0;
}
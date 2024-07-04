#include<iostream>
using namespace std;


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



int main(){
    
    return 0;
}

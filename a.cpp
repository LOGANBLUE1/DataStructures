#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    vector<int> v(n, 2);
    sort(v.begin(), v.end());

    // for(int i=0;i<n;i++)
    //     cin>>v[i];
    int sum = 0;
    for(int i=0;i<n;i++)
        sum += v[i];
    cout<<sum<<endl;
    return 0;
}
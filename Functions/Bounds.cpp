#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>zeros;
    vector<int> nextZero(zeros.size());
    
    for(int i=0;i<zeros.size();++i)
        nextZero[i] = *upper_bound(zeros.begin(),zeros.end(),i);
    
    return 0;
}
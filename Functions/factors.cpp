#include<iostream>
using namespace std;



vector<int> findFactors(int n) {
    //not sorted
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



int main(){
    auto ans = findFactors(24);
    for (auto it:ans)
    {
        cout<<it<<" ";
    }
    
    return 0;
}
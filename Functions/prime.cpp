#include<iostream>
using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}


vector<bool> seive(int n){
    vector<bool>v(n+1,true);
    v[0] = false, v[1] = false;

    for(int i=2;i*i<=n;i++){
        if(v[i] == true){
            int j = i*i;
            while(j <= n){
                v[j] = false;
                j += i;
            }
        }
    }
    return v;
}

vector<int> primeNumbers(int n){
    vector<int>ans;
    auto v = seive(n);
    for(int i=0;i<=n;i++)
        if(v[i])  
            ans.push_back(i);
    return ans;
}

// vector<bool> isPrimeVector(const vector<int>& numbers) {
//     vector<bool> result;
//     for (int num : numbers) {
//         result.push_back(isPrime(num));
//     }
//     return result;
// }



int main(){
    
    return 0;
}
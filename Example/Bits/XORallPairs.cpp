#include<bits/stdc++.h>
using namespace std;
void solve()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    // xor of all pairs like 5C2 -> 10 pairs
    int n = arr.size();
    int freq[32] {};
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 32; j++) {
            if(arr[i] & (1 << j)) {
                freq[j]++;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 32; i++) {
        if(freq[i] == 0) continue;
        ans += (freq[i]*(n-freq[i]))<<i;
    }
    cout<<ans<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    solve();
    return 0;
}
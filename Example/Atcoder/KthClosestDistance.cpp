#include <bits/stdc++.h>
using namespace std;

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    int b,k;
    for (int i = 0; i < Q; i++) {
        cin>>b>>k;
        int lo = 0, hi = 2E8;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            
            int l = b - mid;
            int r = b + mid;
            
            int cnt = upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
            if (cnt >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << "\n";
    }
    
    return 0;
}

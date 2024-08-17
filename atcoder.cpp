#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    int N, X, Y;
    cin >> N >> X >> Y;
    vector dp(N + 1, vector<int>(X + 1, INF));
    dp[0][0] = 0;
    for (int k = 0; k < N; k++) {
        int A, B;
        cin >> A >> B;
        for (int i = N - 1; i >= 0; i--) {
            for (int j = 0; j + A <= X; j++) {
                dp[i + 1][j + A] = max(dp[i + 1][j + A], dp[i][j] + B);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= X; j++) {
            if (dp[i][j] <= Y) {
                ans = min(ans, i + 1);
            }
        }
    }

    cout << ans << "\n";
    return 0;
}
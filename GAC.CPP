class Solution {
public:
    using ll = long long;
    using frac = pair<ll,ll>;

    frac reduce(frac f) {
        ll g = gcd(f.first, f.second);
        return {f.first / g, f.second / g};
    }

    long long countSequences(vector<int>& nums, long long k) {
        map<frac, long long> cur, nxt;
        cur[{1, 1}] = 1;

        for (int x : nums) {
            nxt.clear();
            for (auto &[f, cnt] : cur) {
                ll [num, den] = f;

                nxt[f] += cnt;

                {
                    frac nf = reduce({num * x, den});
                    nxt[nf] += cnt;
                }

                {
                    frac nf = reduce({num, den * x});
                    nxt[nf] += cnt;
                }
            }
            cur.swap(nxt);
        }

        long long ans = 0;
        for (auto &[f, cnt] : cur) {
            if ((__int128)f.first == (__int128)k * f.second)
                ans += cnt;
        }

        return ans;
    }
};

#include <bits/stdc++.h>
using namespace std;

enum Op { SUM, MIN, MAX };

class Seg {
    int n;
    Op op;
    vector<int> t;

    inline int merge(int a, int b) const {
        if (op == SUM) return a + b;
        else if (op == MIN) return min(a, b);
        else if(op == MAX) return max(a, b);
        else throw invalid_argument("Invalid Type of tree");
    }

    inline int neutral() const {
        if (op == SUM) return 0;
        else if (op == MIN) return INT_MAX;
        else if (op == MAX) return INT_MIN;
        else throw invalid_argument("Invalid Type of tree");
    }

    void build(int v, int l, int r, const vector<int>& a) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build((v << 1) + 1, l, m, a);
        build((v+1)<<1, m+1, r, a);
        t[v] = merge(t[(v << 1) + 1], t[(v+1)<<1]);
    }

    void update(int v, int l, int r, int pos, int val) {
        if (l == r) {
            t[v] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos <= m) update((v << 1) + 1, l, m, pos, val);
        else update((v+1)<<1, m+1, r, pos, val);
        t[v] = merge(t[(v << 1) + 1], t[(v+1)<<1]);
    }

    int query(int v, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return neutral();
        if (ql <= l && r <= qr) return t[v];
        int m = (l + r) >> 1;
        return merge(
            query((v << 1) + 1, l, m, ql, qr),
            query((v+1)<<1, m+1, r, ql, qr)
        );
    }

public:
    Seg(int n, Op op) : n(n), op(op), t(4*n) {}

    void build(const vector<int>& a) {
        build(0, 0, n-1, a);
    }

    void update(int pos, int val) {
        update(0, 0, n-1, pos, val);
    }

    int query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};

int main() {
    int n = 5;
    Seg seg(n, SUM);

    seg.build(vector<int>(n, 1));
    cout << seg.query(0, 2) << endl;
}

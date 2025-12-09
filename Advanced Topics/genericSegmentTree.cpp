#include <bits/stdc++.h>
using namespace std;

class SEG {
    vector<int> seg;
    char type;
public:
    SEG(int n, char type_) : type(type_) {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int start, int end, int a[]) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int start, int end, int idx, int val, int a[]) {
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx >= start && idx <= mid)
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);

        seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int start, int end, int L, int R, int a[]) {
        if (R < start || end < L) {
            if (type == 's') return 0;
            if (type == 'm') return INT_MAX;
            if (type == 'x') return INT_MIN;
            return 0;
        }
        if (L <= start && end <= R) {
            return seg[ind];
        }
        int mid = (start + end) >> 1;
        int left = query(2 * ind + 1, start, mid, L, R, a);
        int right = query(2 * ind + 2, mid + 1, end, L, R, a);
        return op(left, right);
    }

private:
    int op(int a, int b) {
        if (type == 's') return a + b;
        else if (type == 'm') return min(a, b);
        else if (type == 'x') return max(a, b);
        else return a + b; // fallback to sum
    }
};

//Lazy
class SEGL {
    vector<int> seg, lazy;
    function<int(int, int)> op;
    char type;
public:
    SEGL(int n, char type_): type(type_)  {
        seg.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
        if (this->type == 's') op = [](int a, int b) { return a + b; };
        else if (this->type == 'm') op = [](int a, int b) { return min(a, b); };
        else if (this->type == 'x') op = [](int a, int b) { return max(a, b); };
        else throw invalid_argument("Unknown segment tree type");
    }

    void build(int ind, int start, int end, int a[]) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int start, int end, int idx, int val, int a[]) {
        if (lazy[ind] != 0) {
            seg[ind] += (end - start + 1) * lazy[ind]; // Only correct for sum
            if (start != end) {
                lazy[2 * ind + 1] += lazy[ind];
                lazy[2 * ind + 2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx >= start && idx <= mid)
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);
        seg[ind] = op(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int start, int end, int L, int R, int a[]) {
        if (R < start || end < L) {
            if (this->type == 's') return 0;
            if (this->type == 'm') return INT_MAX;
            if (this->type == 'x') return INT_MIN;
            return 0; // fallback
        }
        if (L <= start && end <= R) return seg[ind];
        int mid = (start + end) >> 1;
        int left = query(2 * ind + 1, start, mid, L, R, a);
        int right = query(2 * ind + 2, mid + 1, end, L, R, a);
        return op(left, right);
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = 6;
    SEGL sg_sum(n, 's');
    sg_sum.build(0, 0, n - 1, arr);
    cout << "Sum: " << sg_sum.query(0, 0, n - 1, 1, 4, arr) << endl;

    SEGL sg_min(n, 'm');
    sg_min.build(0, 0, n - 1, arr);
    cout << "Min: " << sg_min.query(0, 0, n - 1, 1, 4, arr) << endl;

    SEGL sg_max(n, 'x');
    sg_max.build(0, 0, n - 1, arr);
    cout << "Max: " << sg_max.query(0, 0, n - 1, 1, 4, arr) << endl;
}
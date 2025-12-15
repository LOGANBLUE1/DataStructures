#include<bits/stdc++.h>
using namespace std;

// sum tree
class SEG{
    vector<int>seg;
public:
    SEG(int n): seg(4*n + 1) {}

    void build(int ind, int start, int end, vector<int>&a) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int start, int end, int idx, int val, vector<int>&a) {
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        } 

        int mid = (start + end)>>1;
        if (idx >= start && idx <= mid) 
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int start, int end, int L, int R, vector<int>&a) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return seg[ind];
        }

        int mid = (start + end)>>1;
        int left_MAX = query(2 * ind + 1, start, mid, L, R, a);
        int right_MAX = query(2 * ind + 2, mid + 1, end, L, R, a);
        return left_MAX + right_MAX;
    }
};

// max tree
class SEG2 {
    vector<int> seg;
public:
    SEG2(int n): seg(4*n + 1) {}

    void build(int ind, int start, int end, vector<int>&a) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int start, int end, int idx, int val, vector<int>&a) {
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid)
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) return -1e9;
        if (L <= start && end <= R) return seg[ind];

        int mid = (start + end) >> 1;
        int left_max = query(2 * ind + 1, start, mid, L, R);
        int right_max = query(2 * ind + 2, mid + 1, end, L, R);
        return max(left_max, right_max);
    }
};

// max tree better version
class MAX {
    int n;
    vector<int> seg;
    void build(int ind, int start, int end, vector<int>&a) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    void update(int ind, int start, int end, int idx, int val, vector<int>&a) {
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        }
        int mid = (start + end) >> 1;
        if (idx <= mid)
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);

        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
    
    int query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) return -1;
        if (L <= start && end <= R) return seg[ind];

        int mid = (start + end) >> 1;
        int left_max = query(2 * ind + 1, start, mid, L, R);
        int right_max = query(2 * ind + 2, mid + 1, end, L, R);
        return max(left_max, right_max);
    }
public:
    MAX(int n): n(n), seg(4*n + 1) {}

    void build(vector<int>&a){
        this->build(0, 0, n-1, a);
    }
    void update(int idx, int val, vector<int>&a) {
        this->update(0, 0, n-1, idx, val, a);
    }
    int query(int L, int R){
        return this->query(0, 0, n-1, L, R);
    }
};

// sum tree better version
class SUM{
    int n;
    vector<int>seg;

    void build(int ind, int start, int end, vector<int>&a) {
        if (start == end) {
            this->seg[ind] = a[start];
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        this->seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int start, int end, int idx, int val, vector<int>&a) {
        if (start == end) {
            a[idx] = val;
            this->seg[ind] = val;
            return;
        } 

        int mid = (start + end)>>1;
        if (idx >= start && idx <= mid) 
            update(2 * ind + 1, start, mid, idx, val, a);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a);

        this->seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return this->seg[ind];
        }

        int mid = (start + end)>>1;
        int left_MAX = query(2 * ind + 1, start, mid, L, R);
        int right_MAX = query(2 * ind + 2, mid + 1, end, L, R);
        return left_MAX + right_MAX;
    }
public:
    SUM(int n): n(n), seg(4*n + 1) {}

    void build(vector<int>&a){
        this->build(0, 0, n-1, a);
    }
    void update(int idx, int val, vector<int>&a) {
        this->update(0, 0, n-1, idx, val, a);
    }
    int query(int L, int R){
        return this->query(0, 0, n-1, L, R);
    }
};

int main() {
    vector<int>arr = {1,2,3,4,5,6};
    int n = 6;
    SEG sg(n);
    sg.build(0,0,n-1,arr);
    // cout<<sg.query(1,4)<<endl;
}
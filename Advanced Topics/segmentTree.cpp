#include<bits/stdc++.h>
using namespace std;
// Segment tree (sum)
class SEG{
    vector<int>seg;
public:
    SEG(int n){
        seg.resize(4*n+1);
    }

    void build(int ind, int start, int end, int a[]) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int start, int end, int idx, int val, int a[]) {
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

    int query(int ind, int start, int end, int L, int R, int a[]) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return seg[ind];
        }

        int mid = (start + end)>>1;
        int left_sum = query(2 * ind + 1, start, mid, L, R, a);
        int right_sum = query(2 * ind + 2, mid + 1, end, L, R, a);
        return left_sum + right_sum;
    }
};


// max tree
class SEG2 {
    vector<int> seg;
public:
    SEG2(int n) {
        seg.resize(4 * n + 1);
    }

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
        return max(query(2 * ind + 1, start, mid, L, R),
                   query(2 * ind + 2, mid + 1, end, L, R));
    }
};

// max tree small version
class SEG3 {
    int n;
    vector<int> seg;
public:
    SEG3(int n) {
        this->n = n;
        seg.resize(4 * n + 1);
    }

    void build(int ind, vector<int>&a){
        build(ind,0,n-1,a);
    }

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

    void update(int idx, int val, vector<int>&a) {
        update(0,0,n-1,idx,val,a);
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
    int query(int ind, int L, int R){
        return query(ind, 0, n-1, L, R);
    }
    int query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) return -1;
        if (L <= start && end <= R) return seg[ind];

        int mid = (start + end) >> 1;
        return max(query(2 * ind + 1, start, mid, L, R),
                   query(2 * ind + 2, mid + 1, end, L, R));
    }
};

int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    SEG sg1(n);
    sg1.build(0,0,n-1,arr);
    cout<<sg1.query(0,0,n-1,1,4,arr)<<endl;
}
#include<bits/stdc++.h>
using namespace std;
// Segment tree
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


int main() {
    int arr[] = {1,2,3,4,5,6};
    int n = 6;
    SEG sg1(n);
    sg1.build(0,0,n-1,arr);
    cout<<sg1.query(0,0,n-1,1,4,arr)<<endl;
}
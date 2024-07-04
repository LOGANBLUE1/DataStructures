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
            seg[ind] += a[start];
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    void update(int ind, int start, int end, int idx, int val) {
        if (start == end) {
            seg[ind] += val;
            return;
        } 

        int mid = (start + end)>>1;
        if (idx >= start && idx <= mid) 
            update(2 * ind + 1, start, mid, idx, val);
        else
            update(2 * ind + 2, mid + 1, end, idx, val);

        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }

    int query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return 0;
        }
        if (L <= start && end <= R) {
            return seg[ind];
        }

        int mid = (start + end)>>1;
        int left_sum = query(2 * ind + 1, start, mid, L, R);
        int right_sum = query(2 * ind + 2, mid + 1, end, L, R);
        return left_sum + right_sum;
    }
};


int main() {
    int n;
    cin>>n;
    int a[n];
    int mx = -1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mx = max(mx,a[i]);
    }
    mx += 1;
    int freq[mx];
    for (size_t i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    
    int cnt = 0;
    SEG sg1(mx);
    sg1.build(0,0,mx-1,freq);
    for (size_t i = 0; i < n; i++)
    {
        freq[a[i]]--;
        sg1.update(0, 0, mx-1,a[i], -1);
        cnt += sg1.query(0, 0, mx-1, 1, a[i]-1);
    }
    cout<<cnt<<endl;
}
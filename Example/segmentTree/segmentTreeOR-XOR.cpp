#include<bits/stdc++.h>
using namespace std;
// Segment tree
class SEG{
public:
    vector<int>seg;
    SEG(int n){
        seg.resize(4*n+1);
    }

    void build(int ind, int start, int end, int a[], bool orr) {
        if (start == end) {
            seg[ind] = a[start];
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a, !orr);
        build(2 * ind + 2, mid + 1, end, a, !orr);
        if(orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else    seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }

    void update(int ind, int start, int end, int idx, int val, int a[], bool orr) {
        if (start == end) {
            a[idx] = val;
            seg[ind] = val;
            return;
        } 

        int mid = (start + end)>>1;
        if (idx >= start && idx <= mid) 
            update(2 * ind + 1, start, mid, idx, val, a, !orr);
        else
            update(2 * ind + 2, mid + 1, end, idx, val, a, !orr);

        if(orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else    seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
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
void update(int ind, int start, int end, int idx, int val, int a[], bool orr);

int main() {
    int n,q;
    cin>>n>>q;
    int len = (1<<n);
    int a[len];
    for(int i=0;i<len;i++)
        cin>>a[i];
    SEG seg(len);
    if(n&1)     seg.build(0,0,len-1,a,1);
    else        seg.build(0,0,len-1,a,0);
    for(int i=0;i<q;i++){
        int ind,val;
        cin>>ind>>val;
        ind--;
        if(n&1) seg.update(0,0,len-1,ind,val,a,1);
        else    seg.update(0,0,len-1,ind,val,a,0);
        cout<<seg.seg[0]<<endl;
    }
    return 0;
}
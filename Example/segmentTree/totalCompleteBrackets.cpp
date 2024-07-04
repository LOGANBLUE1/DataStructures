#include<bits/stdc++.h>
using namespace std;

class info{
public:
    int open,close,full;
    info(int open, int close, int full){
        this->open = open;
        this->close = close;
        this->full = full;
    }
    info(){
        this->open = 0;
        this->close = 0;
        this->full = 0;
    }
};

info merge(const info& left, const info& right) {
    info ans;
    int matched = min(left.open, right.close);

    ans.full = left.full + right.full + matched;
    ans.open = left.open + right.open - matched;
    ans.close = left.close + right.close - matched;
    return ans;
}

class SEG{
public:
    vector<info> seg;
    SEG(int n){
        seg.resize(4*n+1);
    }

    void build(int ind, int start, int end, string& a) {
        if (start == end) {
            if(a[start] == '(')
                seg[ind].open = 1;
            else 
                seg[ind].close = 1;
            seg[ind].full = 0;
            return;
        } 

        int mid = (start + end)>>1;
        build(2 * ind + 1, start, mid, a);
        build(2 * ind + 2, mid + 1, end, a);
        seg[ind] = merge(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    info query(int ind, int start, int end, int L, int R) {
        if (R < start || end < L) {
            return info();
        }
        if (L <= start && end <= R) {
            return seg[ind];
        }

        int mid = (start + end)>>1;
        info left = query(2 * ind + 1, start, mid, L, R);
        info right = query(2 * ind + 2, mid + 1, end, L, R);

        return merge(left, right);
    }

    // void update(int ind, int start, int end, int idx, int val, string& a) {
    //     if (start == end) {
    //         full[ind] = 0;
    //         if(a[start] == '(')
    //             open[ind] = 1, close[ind] = 0;
    //         else 
    //             close[ind] = 1, open[ind] = 0;
    //         return;
    //     } 

    //     int mid = (start + end)>>1;
    //     if (idx >= start && idx <= mid) 
    //         update(2 * ind + 1, start, mid, idx, val, a);
    //     else
    //         update(2 * ind + 2, mid + 1, end, idx, val, a);

    //     int ful = min(open[2 * ind + 1],close[2 * ind + 2]);
    //     full[ind] = ful;
    //     full[ind] = full[2 * ind + 1] + full[2 * ind + 2] + ful;
    //     open[ind] = open[2 * ind + 1] + open[2 * ind + 2] - ful;
    //     close[ind] = close[2 * ind + 1] + close[2 * ind + 2] - ful;
    // }
};


int main() {
    string s;
    cin>>s;
    int n = s.size();
    SEG sg1(n);
    sg1.build(0,0,n-1,s);
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        info ans = sg1.query(0,0,n-1,l,r);
        cout<<2*ans.full<<endl;
    }
    return 0;
}
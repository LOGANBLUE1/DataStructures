#include<bits/stdc++.h>
using namespace std;
class ST {
    int n;
    vector<int> seg, lazy;

	void build(int ind, int low, int high, vector<int>& arr) {
		if(low == high) {
			seg[ind] = arr[low];
			return; 
		}
		int mid = (low + high) >> 1; 
		build(2*ind+1, low, mid, arr); 
		build(2*ind+2, mid+1, high, arr); 
		seg[ind] = seg[2*ind+1] + seg[2*ind+2];
	}

    inline void push(int v, int l, int r) {
        if (!lazy[v]) return;
        seg[v] += (r - l + 1) * lazy[v];
        if (l != r) {
            lazy[2*v+1] += lazy[v];
            lazy[2*v+2] += lazy[v];
        }
        lazy[v] = 0;
    }

    void update(int v, int l, int r, int ql, int qr, int val) {
        push(v, l, r);
        if (qr < l || r < ql) return;
        if (ql <= l && r <= qr) {
            lazy[v] += val;
            push(v, l, r);
            return;
        }
        int m = (l + r) >> 1;
        update(2*v+1, l, m, ql, qr, val);
        update(2*v+2, m+1, r, ql, qr, val);
        seg[v] = seg[2*v+1] + seg[2*v+2];
    }

    int query(int v, int l, int r, int ql, int qr) {
        push(v, l, r);
        if (qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return seg[v];
        int m = (l + r) >> 1;
        return query(2*v+1, l, m, ql, qr) + query(2*v+2, m+1, r, ql, qr);
    }

public:
    ST(int n): n(n), seg(4*n), lazy(4*n) {}

	void build(vector<int>&a) {
		this->build(0, 0, n-1, a);
	}

    void update(int l, int r, int val) {
        this->update(0, 0, n-1, l, r, val);
    }

    int query(int l, int r) {
        return this->query(0, 0, n-1, l, r);
    }
};
int main() {
    vector<int> arr = {1,2,3,4,5,6};
    int n = 6;
    ST sg1(n);
    sg1.build(arr);
    cout<<sg1.query(1,4)<<endl;
}
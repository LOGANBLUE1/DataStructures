#include <bits/stdc++.h>
using namespace std;

class BIT {
    int N;
public:
    vector<int> bit;
    BIT(int N) {
        this->N = N;
        bit.resize(N + 1, 0); 
    }

    void update(int i, int diff) {
        i++;
        for (; i <= N; i += (i & -i))
            bit[i] += diff;
    }

    int prefixSum(int i) {
        i++; 
        int sum = 0;
        for (; i > 0; i -= (i & -i))
            sum += bit[i]; 
        return sum;
    }

    int sumRange(int left, int right) {
        return prefixSum(right) - prefixSum(left-1);
    }

};
int main(){
    vector<int>nums = {5,2,9,-3,5,20,10,-7,2,3,-4,0,-2,15,5};
    int n = nums.size();
    BIT bit(n);
    for (int i = 0; i < n; ++i) {
        bit.update(i, nums[i]);
    }
    return 0;
}